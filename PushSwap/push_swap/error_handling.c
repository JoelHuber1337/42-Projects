/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:38:53 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/09 04:00:22 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int x)
{
	if (x == 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (-1);
}

int	doubles_errors(t_stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_input(char *str)
{
	int	x;

	x = 0;
	if (!(str[x] == '+' || str[x] == '-' || (str[x] >= '0' && str[x] <= '9')))
		return (1);
	if ((str[x] == '+' || str[x] == '-')
		&& !(str[x + 1] >= '0' && str[x + 1] <= '9'))
		return (1);
	while (str[++x])
	{
		if (!(str[x] >= '0' && str[x] <= '9'))
			return (1);
	}
	return (0);
}

void	error_handling(t_stack **a, char **arc, int x)
{
	stfree(a, arc, x);
	write(2, "Error\n", 6);
	exit(1);
}

void	stfree(t_stack **stack, char **arc, int x)
{
	t_stack	*tmp;
	t_stack	*current;
	int		i;

	if (x < 1)
	{
		i = 0;
		while (arc[i])
		{
			free(arc[i]);
			i++;
		}
		free(arc);
	}
	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->number = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
