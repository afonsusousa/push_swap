/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:25:16 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/04 20:14:46 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

void	rev_rotate(t_stack_node **stack_head)
{
	t_stack_node	*last;

	if (!*stack_head || !(*stack_head)->next)
		return ;
	last = get_last(*stack_head);
	last->next = (*stack_head);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next->prev = last;
	(*stack_head) = last;
}

void	rra(t_data *stacks, bool print)
{
	if (stacks->size_a < 2)
		return ;
	rev_rotate(&stacks->a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_data *stacks, bool print)
{
	if (stacks->size_b < 2)
		return ;
	rev_rotate(&stacks->b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_data *stacks, bool print)
{
	if (stacks->size_a < 2 && stacks->size_b < 2)
		return ;
	if (stacks->size_a >= 2)
		rev_rotate(&stacks->a);
	if (stacks->size_b >= 2)
		rev_rotate(&stacks->b);
	if (!print)
		ft_printf("rrr\n");
}
