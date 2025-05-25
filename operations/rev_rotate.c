/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:25:16 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/24 17:10:58 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

void    rev_rotate(t_stack_node **stack_head)
{
    t_stack_node    *last;

    if (!*stack_head || !(*stack_head)->next)
        return;
    last = get_last(*stack_head);
    last->next = (*stack_head);
    last->prev->next = NULL;
    last->prev = NULL;
    last->next->prev = last;
    (*stack_head) = last;
}

void    rra(t_stack_node **a, bool print)
{
    rev_rotate(a);
    if (!print)
        ft_printf("rra\n");
}

void    rrb(t_stack_node **b, bool print)
{
    rev_rotate(b);
    if (!print)
        ft_printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rev_rotate(a);
    rev_rotate(b);
    if (!print)
        ft_printf("rrr\n");
}