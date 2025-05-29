/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:53:43 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 18:19:14 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

void    send_node_to_b(t_stack_node *src, t_data *data)
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
            ra(data, false);
        while(src->target->cost--)
            rb(data, false);
    } 
    else if (src->reverse && !src->target->reverse)
    {
        while(src->cost--)
            rra(data, false);
        while(src->target->cost--)
            rb(data, false);
    } else if (src->target->reverse && !src->reverse)
    {
        while(src->cost--)
            ra(data, false);
        while(src->target->cost--)
            rrb(data, false);
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
            rra(data, false);
        while(src->target->cost--)
            rrb(data, false);
    }
    pb(data, false);
}
