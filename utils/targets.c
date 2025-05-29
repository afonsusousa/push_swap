/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:11:07 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 17:19:36 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static t_stack_node    *get_target_a_to_b(t_stack_node *src_node, t_stack_node *dest_stack)
{
    t_stack_node *best_match;
    long         best_match_val;

    best_match = get_max(dest_stack);
    best_match_val = LONG_MIN;
    while (dest_stack)
    {
        if(dest_stack->val < src_node->val && dest_stack->val > best_match_val)
        {
            best_match = dest_stack;
            best_match_val = dest_stack->val;
        }
        dest_stack = dest_stack->next;
    }
    return (best_match);
}

static t_stack_node    *get_target_b_to_a(t_stack_node *src_node, t_stack_node *dest_stack)
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

void update_targets(t_data *data)
{
    t_stack_node *a;
    t_stack_node *b;

    a = data->a;
    b = data->b;
    while (a)
    {
        a->target = get_target_a_to_b(a, data->b);
        a = a->next;
    }
    while (b)
    {
        b->target = get_target_b_to_a(b, data->a);
        b = b->next;
    }
}