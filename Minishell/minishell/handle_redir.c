/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:12:12 by oltolmac          #+#    #+#             */
/*   Updated: 2025/06/09 19:50:18 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	heredoc_redir(char *file, t_mini *mini)
{
	int		fd;
	char	*file_open;

	file_open = remove_quotes(file);
	fd = open(file_open, O_RDONLY);
	if (fd < 0)
	{
		free(file_open);
		open_error(mini);
	}
	else
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			close(fd);
			dup_error(mini);
		}
		if (unlink(file_open))
		{
			close(fd);
			free_exit_procces(mini, NULL);
		}
		close(fd);
	}
	free(file_open);
}

void	redirout_sys(char *file, t_mini *mini)
{
	int		fd;
	char	*file_open;

	file_open = remove_quotes(file);
	fd = open(file_open, O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd < 0)
	{
		free(file_open);
		open_error(mini);
	}
	else
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			close(fd);
			dup_error(mini);
		}
		close(fd);
	}
	free(file_open);
}

void	appredirout_sys(char *file, t_mini *mini)
{
	int		fd;
	char	*file_open;

	file_open = remove_quotes(file);
	fd = open(file_open, O_CREAT | O_RDWR | O_APPEND, 0664);
	if (fd < 0)
	{
		free(file_open);
		open_error(mini);
	}
	else
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			close(fd);
			dup_error(mini);
		}
		close(fd);
	}
	free(file_open);
}

void	redirin_sys(char *file, t_mini *mini)
{
	int		fd;
	char	*file_open;

	file_open = remove_quotes(file);
	fd = open(file_open, O_RDONLY);
	if (fd < 0)
	{
		free(file_open);
		open_error(mini);
	}
	else
	{
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			close(fd);
			dup_error(mini);
		}
		close(fd);
	}
	free(file_open);
}

void	handle_redir(t_mini *mini, t_cmd *cmd, int last)
{
	int		i;
	char	*token;
	char	*file;

	i = 0;
	(void)last;
	while (cmd->cmd_w_flags[i])
	{
		token = cmd->cmd_w_flags[i];
		file = cmd->cmd_w_flags[i + 1];
		if (ft_strcmp(token, ">") == 0 || ft_strcmp(token, ">>") == 0
			|| mini->heredoc_flag == 1)
		{
			redirect_out(token, file, mini);
		}
		else if (ft_strcmp(token, "<") == 0 || ft_strcmp(token, "<<") == 0)
		{
			redirect_in(token, file, mini);
		}
		i++;
	}
}
