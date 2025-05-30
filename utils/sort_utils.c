/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 23:02:54 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:06:38 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
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
bool    is_sorted(t_data *stacks)
{
    t_stack_node *a;

    a = stacks->a;
    if (!a)
        return (false);
    while(a->next)
    {
        if(a->val > a->next->val)
            return (false);
        a = a->next;
    }
    return (true);
}

void    get_min_on_top(t_data * stacks)
{
    t_stack_node *min;

    min = get_min(stacks->a);
    update_indexes(stacks);
    while(stacks->a != min)
    {
        if(!min->reverse)
            ra(stacks, false);
        else
            rra(stacks, false);
    }
}
