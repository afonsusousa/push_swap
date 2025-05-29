/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utilc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:53:51 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 18:19:42 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

void    send_node_to_a(t_stack_node *src, t_data *data)
{
    if(!src->reverse && !src->target->reverse)
    {
        while(src->cost && src->target->cost)
        {
            rr(data, false);
            src->cost--;
            src->target->cost--;
        }
        while(src->cost--)
            rb(data, false);
        while(src->target->cost--)
            ra(data, false);
    } 
    else if (src->reverse && !src->target->reverse)
    {
        while(src->cost--)
            rrb(data, false);
        while(src->target->cost--)
            ra(data, false);
    } else if (src->target->reverse && ! src->reverse)
    {
        while(src->cost--)
            rb(data, false);
        while(src->target->cost--)
            rra(data, false);
    }
    else
    {
        while(src->cost && src->target->cost)
        {
            rrr(data, false);
            src->cost--;
            src->target->cost--;
        }
        while(src->cost--)
            rrb(data, false);
        while(src->target->cost--)
            rra(data, false);
    }
    pa(data, false);
}