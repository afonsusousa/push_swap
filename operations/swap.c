/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:40:21 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:26:08 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

void    swap(t_stack_node **stack_head)
{
    *stack_head = (*stack_head)->next;
    (*stack_head)->prev->prev = *stack_head;
    (*stack_head)->prev->next = (*stack_head)->next;
    if((*stack_head)->next)
        (*stack_head)->next->prev = (*stack_head)->prev;
    (*stack_head)->next = (*stack_head)->prev;
    (*stack_head)->prev = NULL;
}

void	sa(t_data *stacks, bool print)
{
	swap(&stacks->a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_data *stacks, bool print)
{
	swap(&stacks->b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_data *stacks, bool print)
{
	swap(&stacks->a);
	swap(&stacks->b);
	if (!print)
		ft_printf("ss\n");
}