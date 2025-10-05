/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:43:04 by oltolmac          #+#    #+#             */
/*   Updated: 2025/06/12 18:03:59 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*temp_file(int index, t_mini *mini)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	mini->heredoc_buf = ft_strdup("/tmp/minishell_heredoc");
	if (!mini->heredoc_buf)
		return (NULL);
	i = 0;
	while (i < index)
	{
		tmp = ft_strdup(mini->heredoc_buf);
		free(mini->heredoc_buf);
		if (!tmp)
			return (NULL);
		mini->heredoc_buf = ft_strjoin(tmp, "e");
		free(tmp);
		if (!mini->heredoc_buf)
			return (NULL);
		i++;
	}
	return (mini->heredoc_buf);
}

int	check_q_exp(t_mini *mini, char *line)
{
	int		i;
	char	**tok;
	int		j;

	i = 0;
	if (ft_strchr(line, '$') == NULL)
		i++;
	tok = ft_split(mini->cmd_line, '<');
	if (!tok)
		free_exit_heredoc(mini, "Malloc Fail in heredoc", line);
	j = 0;
	while (tok[j])
		j++;
	if (ft_strchr(tok[j - 1], '"') != NULL)
		i++;
	if (ft_strchr(tok[j - 1], '\'') != NULL)
		i++;
	free_2d_array(tok);
	return (i);
}

static void	heredoc_child(int fd, char *delimiter, t_mini *mini)
{
	char	*line;

	signal(SIGINT, heredoc_signal_handle);
	while (1)
	{
		disable_quit_signals();
		line = readline("> ");
		if (g_global == SIGINT)
			sigint_exithere(mini, line);
		if (!line && g_global != SIGINT)
			heredoc_warn(mini, delimiter, line);
		if (line && ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		if (line && check_q_exp(mini, line) == 0)
			line = here_expansion(mini, line, 0, 0);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	free_exit_heredoc(mini, NULL, NULL);
}

int	heredoc_handle(t_mini *mini, char *delimiter, int index)
{
	pid_t	pid;
	int		status;

	if (mini->heredoc_buf)
		free(mini->heredoc_buf);
	mini->heredoc_buf = temp_file(index, mini);
	if (!mini->heredoc_buf)
		return (0);
	mini->here_fd = open(mini->heredoc_buf, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (mini->here_fd < 0)
		return (0);
	pid = fork();
	if (pid < 0)
		return (close(mini->here_fd), 0);
	if (pid == 0)
		heredoc_child(mini->here_fd, delimiter, mini);
	close(mini->here_fd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		return (1);
	return (0);
}

int	heredoc_check(t_mini *mini, t_cmd *list)
{
	int	i;

	if (list->redir == 0)
		return (0);
	while (list)
	{
		i = 0;
		while (list->cmd_w_flags && list->cmd_w_flags[i])
		{
			if (ft_strcmp(list->cmd_w_flags[i], "<<") == 0)
			{
				heredoc_handle(mini, list->cmd_w_flags[i + 1], i);
				if (!mini->heredoc_buf)
					free_exit_heredoc(mini, "Heredoc fail", NULL);
				free(list->cmd_w_flags[i + 1]);
				list->cmd_w_flags[i + 1] = ft_strdup(mini->heredoc_buf);
				mini->heredoc_flag = 1;
				if (!list->cmd_w_flags[i + 1])
					return (1);
			}
			i++;
		}
		list = list->next;
	}
	return (0);
}
