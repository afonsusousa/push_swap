/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:29:11 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/25 01:39:36 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_stack_node *append(t_stack_node **stack_head, int val)
{
    t_stack_node *to_append;
    t_stack_node    *last;

    if (!stack_head)
        return (NULL);
    to_append = malloc(sizeof(t_stack_node));
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
}