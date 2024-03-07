/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 06:56:39 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/09 04:13:20 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b, false);
	make_index(*a);
	make_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b, false);
	make_index(*a);
	make_index(*b);
}

void	push_a_to_b(t_stack **a, t_stack**b)
{
	t_stack	*node;

	node = get_cheapest(*a);
	if (node->above && node->target->above)
		rotate_both(a, b, node);
	else if (!(node->above) && !(node->target->above))
		rev_rotate_both(a, b, node);
	push_prep(a, node, 'a');
	push_prep(b, node->target, 'b');
	pb(b, a, false);
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	push_prep(a, (*b)->target, 'a');
	pa(a, b, false);
}

void	target_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = stlen(*a);
	if (len-- > 3 && !sorted(*a))
		pb(b, a, false);
	if (len-- > 3 && !sorted(*a))
		pb(b, a, false);
	while (len-- > 3 && !sorted(*a))
	{
		make_nodes_a(*a, *b);
		push_a_to_b(a, b);
	}
	simple_sort(a);
	while (*b)
	{
		make_nodes_b(*a, *b);
		push_b_to_a(a, b);
	}
	make_index(*a);
	check_top(a);
}
