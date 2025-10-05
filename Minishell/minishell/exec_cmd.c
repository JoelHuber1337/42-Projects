/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:36:37 by oltolmac          #+#    #+#             */
/*   Updated: 2025/06/11 14:20:12 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	error_messeg_path(t_mini *mini, char *mess, int exit, char *path)
{
	mini->exit = exit;
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putendl_fd(mess, STDERR_FILENO);
	return (1);
}

int	dir_check(t_mini *mini, char *path)
{
	struct stat	st;

	if (stat(path, &st) == -1)
	{
		perror(path);
		mini->exit = 127;
		return (1);
	}
	if (S_ISDIR(st.st_mode))
		return (error_messeg_path(mini, " Is a directory", 126, path));
	if (access(path, X_OK) == -1)
		return (error_messeg_path(mini, " Permission denied", 126, path));
	return (0);
}

char	*get_check_path(t_mini *mini, char **envp, char *name)
{
	char	*path_env;
	char	*full_path;

	if (ft_strchr(name, '/') != NULL)
	{
		if (dir_check(mini, name))
			return (NULL);
		return (ft_strdup(name));
	}
	path_env = find_path(mini, envp);
	if (!path_env)
	{
		no_cmd_msg(mini, name);
		return (NULL);
	}
	full_path = find_path_dir(mini, path_env, name);
	if (!full_path)
	{
		no_cmd_msg(mini, name);
		return (NULL);
	}
	if (dir_check(mini, full_path))
		return (free(full_path), NULL);
	return (full_path);
}

void	exec_cmd_call(t_mini *mini, char **ar_cm, t_cmd *cmd, char **envp)
{
	if (is_all_dollars(mini->cmd_line))
	{
		no_cmd_msg(mini, ar_cm[0]);
		free_exit_procces(mini, NULL);
	}
	if (array_is_empty(cmd, ar_cm))
		free_exit_procces(mini, NULL);
	if (!ar_cm || !ar_cm[0] || !ar_cm[0][0])
		free_exit_procces(mini, NULL);
	if (g_global == SIGPIPE)
		free_exit_procces(mini, "Error: Broken pipe\n");
	if (is_built(ar_cm[0]))
	{
		run_built(mini, cmd, cmd->name);
		free_exit_procces(mini, NULL);
	}
	if (mini->b_ex == 1)
		free_exit_procces(mini, NULL);
	cmd->path = get_check_path(mini, envp, cmd->name);
	if (!cmd->path)
		free_exit_procces(mini, NULL);
	execve(cmd->path, ar_cm, mini->benv);
	free_exit_procces(mini, NULL);
}
