/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:12:17 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/28 19:21:01 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

void    rotate(t_stack_node **stack_head)
{
    t_stack_node    *last;

    if (!*stack_head || !(*stack_head)->next)
        return ;
    last = get_last(*stack_head);
    last->next = (*stack_head);
    (*stack_head)->next->prev = NULL;
    (*stack_head) = (*stack_head)->next;
    last->next->prev = last;
    last->next->next = NULL;
}

void    ra(t_data *data, bool print)
{
    rotate(&data->a);
    if (!print)
        ft_printf("ra\n");
}

void    rb(t_data *data, bool print)
{
    rotate(&data->b);
    if (!print)
        ft_printf("rb\n");
}

void    rr(t_data *data, bool print)
{
    rotate(&data->a);
    rotate(&data->b);
    if (!print)
        ft_printf("rr\n");
}