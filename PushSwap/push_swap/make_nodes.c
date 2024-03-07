/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:19:31 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/09 04:00:46 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest(t_stack *stack)
{
	long			smallest;
	t_stack			*node;

	if (!stack)
		return ;
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->cost < smallest)
		{
			smallest = stack->cost;
			node = stack;
		}
		stack = stack->next;
	}
	node->cheapest = true;
}

void	costs_a(t_stack *a, t_stack *b)
{
	int	x;
	int	y;

	x = stlen(a);
	y = stlen(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above))
			a->cost = x - (a->index);
		if (a->target->above)
			a->cost += a->target->index;
		else
			a->cost += y - (a->target->index);
		a = a->next;
	}
}

void	targets_a(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	long	match;

	while (a)
	{
		match = LONG_MIN;
		current = b;
		while (current)
		{
			if (current->number < a->number && current->number > match)
			{
				match = current->number;
				target = current;
			}
			current = current->next;
		}
		if (match == LONG_MIN)
			a->target = find_biggest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	make_index(t_stack *stack)
{
	int	x;
	int	half;

	x = 0;
	if (!stack)
		return ;
	half = stlen(stack) / 2;
	while (stack)
	{
		stack->index = x;
		if (x <= half)
			stack->above = true;
		else
			stack->above = false;
		stack = stack->next;
		x++;
	}
}

void	make_nodes_a(t_stack *a, t_stack *b)
{
	make_index(a);
	make_index(b);
	targets_a(a, b);
	costs_a(a, b);
	cheapest(a);
}
