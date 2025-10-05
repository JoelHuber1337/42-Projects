/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:18:15 by johuber           #+#    #+#             */
/*   Updated: 2025/06/11 17:46:08 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	cl_fd(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}

void	ft_free_cmd(t_mini *mini)
{
	t_cmd	*tmp;

	tmp = mini->cmd;
	while (tmp)
	{
		if (tmp->cmd_w_flags)
			free_2d_array(tmp->cmd_w_flags);
		if (tmp->cmd_no_redir)
			free_2d_array(tmp->cmd_no_redir);
		if (tmp->name)
			free(tmp->name);
		if (tmp->free)
			free(tmp->free);
		if (tmp->path)
			free(tmp->path);
		tmp = tmp->next;
	}
	while (mini->cmd)
	{
		tmp = mini->cmd;
		mini->cmd = mini->cmd->next;
		free(tmp);
	}
	mini->cmd = NULL;
}

void	ft_free_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->value)
			free(tmp->value);
		if (tmp->name)
			free(tmp->name);
		tmp = tmp->next;
	}
	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp);
	}
}

void	free_null(char **arr)
{
	free_2d_array(arr);
	arr = NULL;
}

void	free_exit_procces(t_mini *mini, char *str)
{
	int	status;

	status = mini->exit;
	if (str != NULL)
		ft_putstr_fd(str, STDERR_FILENO);
	if (mini->heredoc_buf)
		free(mini->heredoc_buf);
	if (mini->cmd_line)
	{
		free(mini->cmd_line);
		mini->cmd_line = NULL;
	}
	if (mini->benv)
		free_null(mini->benv);
	if (mini->cmd)
	{
		ft_free_cmd(mini);
		mini->cmd = NULL;
	}
	rl_clear_history();
	ft_free_env(mini->env);
	mini->env = NULL;
	close(mini->fd_in);
	close(mini->fd_out);
	exit(status);
}
