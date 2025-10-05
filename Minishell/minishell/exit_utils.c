/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:56:38 by oltolmac          #+#    #+#             */
/*   Updated: 2025/06/11 20:57:14 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	number_exit(t_mini *mini, char **input)
{
	long	number;
	char	*end;

	number = ft_strtol(input[1], &end);
	if (number > INT_MAX || number < INT_MIN)
	{
		mini->exit = 2;
		free_exit_procces(mini, "exit : numeric argument required\n");
	}
	number = ft_atoi(input[1]);
	return (number);
}
