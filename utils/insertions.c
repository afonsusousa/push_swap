/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:53:51 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/01 20:23:55 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static void rotate_both_forward(t_stack_node *src, t_data *stacks)
{
    while(src->cost && src->target->cost)
    {
        rr(stacks, false);
        src->cost--;
        src->target->cost--;
    }
    while(src->cost--)
        rb(stacks, false);
    while(src->target->cost--)
        ra(stacks, false);
}

static void rotate_src_reverse_target_forward(t_stack_node *src, t_data *stacks)
{
    while(src->cost--)
        rrb(stacks, false);
    while(src->target->cost--)
        ra(stacks, false);
}

static void rotate_src_forward_target_reverse(t_stack_node *src, t_data *stacks)
{
    while(src->cost--)
        rb(stacks, false);
    while(src->target->cost--)
        rra(stacks, false);
}

static void rotate_both_reverse(t_stack_node *src, t_data *stacks)
{
    while(src->cost && src->target->cost)
    {
        rrr(stacks, false);
        src->cost--;
        src->target->cost--;
    }
    while(src->cost--)
        rrb(stacks, false);
    while(src->target->cost--)
        rra(stacks, false);
}

void    send_node_to_a(t_stack_node *src, t_data *stacks)
{
    if(!src->reverse && !src->target->reverse)
        rotate_both_forward(src, stacks);
    else if (src->reverse && !src->target->reverse)
        rotate_src_reverse_target_forward(src, stacks);
    else if (src->target->reverse && !src->reverse)
        rotate_src_forward_target_reverse(src, stacks);
    else
        rotate_both_reverse(src, stacks);
    pa(stacks, false);
}