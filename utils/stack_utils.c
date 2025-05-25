/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:26:16 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/24 18:18:19 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

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

int size(t_stack_node *stack_head)
{
    int i;

    i = 0;
    while(stack_head && ++i)
        stack_head = stack_head->next;
    return (i);
}

t_stack_node *get(t_stack_node *stack_head, int index)
{
    int i;

    i = 0;
    while (stack_head)
    {
        if(i++ == index)
            return (stack_head);
        stack_head = stack_head->next;
    }
    return (NULL);
}