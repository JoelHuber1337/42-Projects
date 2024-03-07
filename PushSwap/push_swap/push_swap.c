/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:00:48 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/09 04:06:02 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>

t_stack	*get_largest(t_stack *stack)
{
	long		max;
	t_stack		*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	simple_sort(t_stack **a)
{
	t_stack	*largest;

	largest = get_largest(*a);
	if (largest == *a)
		ra(a, false);
	else if (largest == (*a)->next)
		rra(a, false);
	if ((*a)->number > (*a)->next->number)
		sa(a, false);
}

void	prepare_a(t_stack **a, char **arc, char **arj, int l)
{
	long	n;
	int		x;

	x = 0;
	while (arc[x])
	{
		if (check_input(arc[x]))
			error_handling(a, arj, l);
		if (ft_strlen(arc[x]) > 12)
			error_handling(a, arj, l);
		n = ft_atoi(arc[x]);
		if (n > INT_MAX || n < INT_MIN)
			error_handling(a, arj, l);
		if (doubles_errors(*a, (int)n))
			error_handling(a, arj, l);
		make_a(a, (int)n);
		x++;
	}
}

int	main(int arv, char **arc)
{
	t_stack	*a;
	t_stack	*b;
	int		x;

	x = 1;
	a = NULL;
	b = NULL;
	if (arv == 2 && !arc[1][0])
		return (error(0));
	else if (arv == 2)
		arc = ft_split(arc[x--], ' ');
	if (arc == NULL)
		return (error(0));
	prepare_a(&a, arc + x, arc, x);
	if (!sorted(a))
	{
		if (stlen(a) == 2)
			sa(&a, false);
		else if (stlen(a) == 3)
			simple_sort(&a);
		else
			target_sort(&a, &b);
	}
	stfree(&a, arc, x);
	return (0);
}
