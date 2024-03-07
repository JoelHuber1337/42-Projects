/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:31:39 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/09 04:09:03 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_biggest(t_stack *stack)
{
	long			max;
	t_stack			*max_current;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_current = stack;
		}
		stack = stack->next;
	}
	return (max_current);
}

t_stack	*find_smallest(t_stack *stack)
{
	long	min;
	t_stack	*current;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			current = stack;
		}
		stack = stack->next;
	}
	return (current);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_prep(t_stack **stack, t_stack *top_current, char name)
{
	while (*stack != top_current)
	{
		if (name == 'a')
		{
			if (top_current->above)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name == 'b')
		{
			if (top_current->above)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	make_a(t_stack **stack, int n)
{
	t_stack	*current;
	t_stack	*last;

	if (!stack)
		return ;
	current = malloc(sizeof(t_stack));
	if (!current)
		return ;
	current->next = NULL;
	current->number = n;
	if (!(*stack))
	{
		*stack = current;
		current->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = current;
		current->prev = last;
	}
}
