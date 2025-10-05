/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:12:20 by johuber           #+#    #+#             */
/*   Updated: 2025/05/31 16:24:46 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	replace_cmd(char **cmd, int heredoc_flag, t_mini *mini, int i)
{
	while (cmd[i])
	{
		if (heredoc_flag == 1 && ft_strcmp(cmd[i], "<<") == 0 && cmd[i + 1])
		{
			free(cmd[i]);
			cmd[i] = ft_strdup(mini->heredoc_buf);
			free(cmd[i + 1]);
			cmd[i + 1] = NULL;
		}
		i++;
	}
}

int	is_redir(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "<") == 0 || ft_strcmp(str[i], ">") == 0
			|| ft_strcmp(str[i], ">>") == 0 || ft_strcmp(str[i], "<<") == 0)
			return (1);
		i++;
	}
	return (0);
}

void	redirect_out(char *oper, char *file, t_mini *mini)
{
	if (ft_strcmp(oper, ">>") == 0)
		appredirout_sys(file, mini);
	else if ((ft_strcmp(oper, ">") == 0))
		redirout_sys(file, mini);
}

void	redirect_in(char *oper, char *file, t_mini *mini)
{
	if (ft_strcmp(oper, "<<") == 0 || mini->heredoc_flag == 1)
		heredoc_redir(file, mini);
	else if ((ft_strcmp(oper, "<") == 0))
		redirin_sys(file, mini);
}
