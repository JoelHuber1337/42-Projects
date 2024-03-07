/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:31:08 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/09 04:04:40 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack, bool print)
{
	t_stack	*last;

	if (!print)
		ft_printf("rra\n");
	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rrb(t_stack **stack, bool print)
{
	t_stack	*last;

	if (!print)
		ft_printf("rrb\n");
	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rra(a, true);
	rrb(b, true);
	if (!print)
		ft_printf("rrr\n");
}
