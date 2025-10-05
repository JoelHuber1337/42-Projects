/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:45:49 by johuber           #+#    #+#             */
/*   Updated: 2025/06/09 19:11:50 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*dol_empty_expansion(t_mini *mini, t_cmd *cmd, char *str)
{
	char	*tmp;

	cmd->x++;
	if (is_quote(str[cmd->x]))
		tmp = ft_strdup("");
	else
		tmp = ft_strdup("$");
	if (!tmp)
	{
		error_msg(mini, "🪐 MiniSheLL 🪐 : Malloc failure in tokenization\n");
		ft_parser_exit(mini, mini->msplit, mini->cmd_line, NULL);
	}
	return (tmp);
}

char	*handle_empty_dquote(t_mini *mini, t_cmd *cmd)
{
	char	*tmp;

	tmp = ft_strdup("");
	if (tmp == NULL)
	{
		error_msg(mini, "🪐 MiniSheLL 🪐 : Malloc failure in tokenization\n");
		ft_parser_exit(mini, mini->msplit, mini->cmd_line, NULL);
	}
	cmd->x++;
	return (tmp);
}

int	calc_merge_quote(char *str, int x)
{
	if (is_dquote(str[x]))
	{
		x++;
		while (str[x] && !is_dquote(str[x]))
			x++;
		x++;
		return (x);
	}
	if (is_squote(str[x]))
	{
		x++;
		while (!is_squote(str[x]) && str[x])
			x++;
		x++;
		return (x);
	}
	return (x);
}

int	sizeofarry(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}
