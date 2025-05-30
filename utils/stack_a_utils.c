/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:53:51 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:05:12 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

void    send_node_to_a(t_stack_node *src, t_data *stacks)
{
    if(!src->reverse && !src->target->reverse)
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
    else if (src->reverse && !src->target->reverse)
    {
        while(src->cost--)
            rrb(stacks, false);
        while(src->target->cost--)
            ra(stacks, false);
    } else if (src->target->reverse && ! src->reverse)
    {
        while(src->cost--)
            rb(stacks, false);
        while(src->target->cost--)
            rra(stacks, false);
    }
    else
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
    pa(stacks, false);
}