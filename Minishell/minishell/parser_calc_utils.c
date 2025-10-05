/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_calc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:13:58 by johuber           #+#    #+#             */
/*   Updated: 2025/06/11 20:44:48 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	skip_token_merge(char *s, int x)
{
	if ((!is_quote(s[x]) && s[x] != '$' && !is_no_tokens(s[x])) || !s[x])
		return (x);
	if (is_quote(s[x]))
		x = calc_merge_quote(s, x);
	else if (s[x] == '$')
	{
		x++;
		while (is_no_tokens(s[x]) && s[x])
		{
			if (s[x] == '?')
			{
				x++;
				break ;
			}
			x++;
		}
	}
	else if (is_no_tokens(s[x]))
	{
		while (is_no_tokens(s[x]) && s[x])
			x++;
	}
	if (is_quote(s[x]) || s[x] == '$' || is_no_tokens(s[x]))
		x = skip_token_merge(s, x);
	return (x);
}

int	calc_char(char *str, int x, int *count)
{
	while (!is_space(str[x]) && !is_quote(str[x])
		&& str[x] && !is_arrow(str[x]) && str[x] != '$')
		x++;
	(*count)++;
	if (str[x] == '$' || is_no_tokens(str[x]) || is_quote(str[x]))
		x = skip_token_merge(str, x);
	return (x);
}

int	calc_arrow(char *str, int x, int *count)
{
	while (is_arrow(str[x]))
		x++;
	(*count)++;
	return (x);
}

int	calc_dollar(char *str, int x, int *count)
{
	x++;
	(*count)++;
	if (is_space(str[x]))
		return (x);
	if (str[x] == '$')
		x++;
	while (!is_space(str[x]) && !is_quote(str[x]) && str[x] != '='
		&& str[x] && !is_arrow(str[x]) && str[x] != '$')
	{
		if (str[x] == '?')
		{
			x++;
			break ;
		}
		x++;
	}
	if (str[x] == '$' || is_no_tokens(str[x]) || is_quote(str[x]))
		x = skip_token_merge(str, x);
	return (x);
}

int	calc_quote(char *str, int x, int *count)
{
	if (is_dquote(str[x]))
	{
		x++;
		(*count)++;
		while (str[x] && !is_dquote(str[x]))
			x++;
		x++;
		if (str[x] == '$' || is_no_tokens(str[x]) || is_quote(str[x]))
			x = skip_token_merge(str, x);
		return (x);
	}
	if (is_squote(str[x]))
	{
		x++;
		(*count)++;
		while (!is_squote(str[x]) && str[x])
			x++;
		x++;
		if (str[x] == '$' || is_no_tokens(str[x]) || is_quote(str[x]))
			x = skip_token_merge(str, x);
		return (x);
	}
	return (x);
}
