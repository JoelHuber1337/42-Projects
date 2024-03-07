/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:38:47 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/09 03:49:35 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stlen(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	t_stack	*target;

	if (!print)
		ft_printf("pa\n");
	if (!*b)
		return ;
	target = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	target->prev = NULL;
	if (!*a)
	{
		*a = target;
		target->next = NULL;
	}
	else
	{
		target->next = *a;
		target->next->prev = target;
		*a = target;
	}
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	t_stack	*target;

	if (!print)
		ft_printf("pb\n");
	if (!*a)
		return ;
	target = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	target->prev = NULL;
	if (!*b)
	{
		*b = target;
		target->next = NULL;
	}
	else
	{
		target->next = *b;
		target->next->prev = target;
		*b = target;
	}
}
