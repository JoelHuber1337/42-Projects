/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:08:22 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/19 15:28:54 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				cost;
	bool			above;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int				main(int arv, char **arc);
void			pa(t_stack **a, t_stack **b, bool print);
void			pb(t_stack **b, t_stack **a, bool print);
void			sa(t_stack	**a, bool print);
void			sb(t_stack **b, bool print);
void			ss(t_stack **a, t_stack **b, bool print);
t_stack			*find_last(t_stack *stack);
void			ra(t_stack **a, bool print);
void			rb(t_stack **b, bool print);
void			rr(t_stack **a, t_stack **b, bool print);
void			rra(t_stack **a, bool print);
void			rrb(t_stack **b, bool print);
void			rrr(t_stack **a, t_stack **b, bool print);
void			simple_sort(t_stack **a);
void			target_sort(t_stack **a, t_stack **b);
t_stack			*get_largest(t_stack *stack);
void			prepare_a(t_stack **a, char **arc, char **arj, int l);
void			make_a(t_stack **stack, int n);
bool			sorted(t_stack *stack);
int				stlen(t_stack *stack);
void			stfree(t_stack **stack, char **arc, int x);
void			init_nodes_a(t_stack *a, t_stack *b);
void			make_index(t_stack *stack);
void			targets_a(t_stack *a, t_stack *b);
t_stack			*find_biggest(t_stack *stack);
t_stack			*get_cheapest(t_stack *stack);
void			costs_a(t_stack *a, t_stack *b);
void			cheapest(t_stack *stack);
void			targets_b(t_stack *a, t_stack *b);
void			push_prep(t_stack **stack, t_stack *top_node, char stack_name);
t_stack			*find_smallest(t_stack *stack);
int				check_input(char *str_n);
void			error_handling(t_stack **a, char **arc, int x);
int				error(int x);
int				doubles_errors(t_stack *a, int n);
void			make_nodes_a(t_stack *a, t_stack *b);
void			make_nodes_b(t_stack *a, t_stack *b);
void			check_top(t_stack **a);

#endif