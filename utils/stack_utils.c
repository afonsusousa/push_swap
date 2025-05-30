/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:26:16 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:12:44 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <limits.h>

t_stack_node    *get_min(t_stack_node *stack_head)
{
    long min;
    t_stack_node *min_node;

    min = LONG_MAX;
    min_node = NULL;
    while(stack_head)
    {
        if(stack_head->val < min)
        {
            min = stack_head->val;
            min_node = stack_head;
        }
        stack_head = stack_head->next;
    }
    return (min_node);
}

t_stack_node    *get_max(t_stack_node *stack_head)
{
    long max;
    t_stack_node *max_node;

    max = LONG_MIN;
    max_node = NULL;
    while(stack_head)
    {
        if(stack_head->val > max)
        {
            max = stack_head->val;
            max_node = stack_head;
        }
        stack_head = stack_head->next;
    }
    return (max_node);
}

t_stack_node *get_last(t_stack_node *stack_head)
{
    if (!stack_head->next)
        return (stack_head);
    while(stack_head)
    {
        if (!stack_head->next)
            break;
        stack_head = stack_head->next;
    }
    return (stack_head);
}

t_stack_node *append(t_stack_node **stack_head, int val)
{
    t_stack_node *to_append;
    t_stack_node    *last;

    if (!stack_head)
        return (NULL);
    to_append = ft_calloc(sizeof(t_stack_node), 1);
    if (!to_append)
        return (NULL);
    to_append->val = val;
    to_append->next = NULL;
    if(!*stack_head)
    {
        (*stack_head) = to_append;
        to_append->prev = NULL;
    }
    else
    {
        last = get_last(*stack_head);
        last->next = to_append;
        last->next->prev = last;
    }
    return (to_append);
}