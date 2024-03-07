/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:31:52 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/09 04:07:02 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ra(t_stack **a, bool print)
{
	t_stack	*last;

	if (!print)
		ft_printf("ra\n");
	if (!*a || !(*a)->next)
		return ;
	last = find_last(*a);
	last->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	rb(t_stack **b, bool print)
{
	t_stack	*last;

	if (!print)
		ft_printf("rb\n");
	last = find_last(*b);
	last->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	ra(a, true);
	rb(b, true);
	if (!print)
		ft_printf("rr\n");
}
