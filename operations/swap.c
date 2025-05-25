/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:40:21 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/24 16:51:40 by amagno-r         ###   ########.fr       */
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

void	sa(t_stack_node	**a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}