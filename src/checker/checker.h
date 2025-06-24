/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:59:27 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/05 18:22:50 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include "../../libft/libft.h"

#define ATOL_ERROR LONG_MAX

typedef struct s_stack_node
{
	int						val;
	int						index;
	int						cost;
	bool					reverse;
	bool					cheapest;
	bool					in_lis;
	int						finalpos;
	struct s_stack_node		*target;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

typedef struct s_data
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				size_a;
	int				size_b;
}	t_data;

//Operations
void				sa(t_data *data, bool print);
void				sb(t_data *data, bool print);
void				ss(t_data *data, bool print);
void				ra(t_data *data, bool print);
void				rb(t_data *data, bool print);
void				rr(t_data *data, bool print);
void				rra(t_data *data, bool print);
void				rrb(t_data *data, bool print);
void				rrr(t_data *data, bool print);
void				pa(t_data *data, bool print);
void				pb(t_data *data, bool print);

//Sorting checks
bool				has_duplicates(t_stack_node *a);
bool				is_sorted(t_data *data);

//List (stacks) utilities
t_stack_node		*append(t_data *stacks, int val);
t_stack_node		*get_last(t_stack_node *stack_head);

//Input utilities
long				ft_atol(char *str);
void				parse_stacks(int argc, char **argv, t_data *stacks);
int					parse_op(t_data *stacks);

//Error handling and frees
void				free_nbrs(char ***nbrs);
void				free_data(t_data *stacks, char ***nbrs);
void				ft_error(t_data *stacks, char ***nbrs);