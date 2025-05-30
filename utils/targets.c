/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:11:07 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:08:34 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static t_stack_node    *get_target(t_stack_node *src_node, t_stack_node *dest_stack)
{
    t_stack_node *best_match;
    long         best_match_val;

    best_match = get_min(dest_stack);
    best_match_val = LONG_MAX;
    while (dest_stack)
    {
        if(dest_stack->val > src_node->val && dest_stack->val < best_match_val)
        {
            best_match = dest_stack;
            best_match_val = dest_stack->val;
        }
        dest_stack = dest_stack->next;
    }
    return (best_match);
}

void update_targets(t_data *stacks)
{
    t_stack_node *b;

    b = stacks->b;
    while (b)
    {
        b->target = get_target(b, stacks->a);
        b = b->next;
    }
}