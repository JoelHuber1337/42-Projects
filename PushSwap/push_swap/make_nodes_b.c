/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:18:12 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/09 03:52:35 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	targets_b(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target_node;
	long	match;

	while (b)
	{
		match = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->number > b->number && current->number < match)
			{
				match = current->number;
				target_node = current;
			}
			current = current->next;
		}
		if (match == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	make_nodes_b(t_stack *a, t_stack *b)
{
	make_index(a);
	make_index(b);
	targets_b(a, b);
}
