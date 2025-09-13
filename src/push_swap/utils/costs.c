/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:43:09 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/02 22:12:23 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static void	set_cost(t_stack_node *current, t_data *stacks, int stack)
{
	int	stack_size;

	stack_size = (!stack * stacks->size_a) + (stack * stacks->size_b);
	if (!current->reverse)
		current->cost = current->index;
	else
		current->cost = stack_size - current->index;
}

void	update_costs(t_data *stacks)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = stacks->a;
	b = stacks->b;
	while (a)
	{
		set_cost(a, stacks, STACK_A);
		a = a->next;
	}
	while (b)
	{
		set_cost(b, stacks, STACK_B);
		b = b->next;
	}
}

void	update_cheapest(t_stack_node *stack_head)
{
	t_stack_node	*current;
	t_stack_node	*cheapest;
	int				mincost;

	mincost = INT_MAX;
	current = stack_head;
	while (current)
	{
		current->cheapest = false;
		if (current->cost + current->target->cost < mincost)
		{
			mincost = current->cost + current->target->cost;
			cheapest = current;
		}
		current = current->next;
	}
	cheapest->cheapest = true;
}
