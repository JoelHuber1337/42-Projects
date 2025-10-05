/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:55:04 by johuber           #+#    #+#             */
/*   Updated: 2025/06/09 20:15:42 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' \
		|| c == '\n' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	rev_skip_spaces(char *str, int x)
{
	while (x > 0)
	{
		if (is_space(str[x]))
			x--;
		else
			break ;
	}
	return (x);
}

int	skip_spaces(char *str, int x)
{
	while (str[x])
	{
		if (is_space(str[x]))
			x++;
		else
			break ;
	}
	return (x);
}

int	skip_quotes(char *str, int x)
{
	if (is_dquote(str[x]))
	{
		x++;
		while (!is_dquote(str[x]) && str[x])
			x++;
		if (str[x])
			x++;
	}
	if (is_squote(str[x]))
	{
		x++;
		while (!is_squote(str[x]) && str[x])
			x++;
		if (str[x])
			x++;
	}
	if (is_dquote(str[x]) || is_squote(str[x]))
		skip_quotes(str, x);
	return (x);
}

char	**calc_tokens(char *str)
{
	int		x;
	int		count;
	char	**res;

	count = 0;
	x = skip_spaces(str, 0);
	while (str[x])
	{
		if (is_quote(str[x]))
			x = calc_quote(str, x, &count);
		else if (str[x] == '$')
			x = calc_dollar(str, x, &count);
		else if (is_arrow(str[x]))
			x = calc_arrow(str, x, &count);
		else if (!is_space(str[x]))
			x = calc_char(str, x, &count);
		if (is_space(str[x]))
			x = skip_spaces(str, x);
	}
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	res[0] = NULL;
	return (res);
}
