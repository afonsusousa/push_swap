/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:33:36 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/25 01:39:24 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

typedef struct s_stack_node
{
    int     val;
    int     index;
    int     cost;
    bool    reverse;
    bool    mincost;

    struct s_stack_node *target;
    struct s_stack_node *next;
    struct s_stack_node *prev;

}	t_stack_node;

void	sa(t_stack_node	**a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);

void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);

void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);


t_stack_node *get_last(t_stack_node *stack_head);
int size(t_stack_node *stack_head);
t_stack_node *get(t_stack_node *stack_head, int index);

t_stack_node *append(t_stack_node **stack_head, int val)
