/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:16:10 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 02:58:03 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../push_swap.h"

static void    update_stack_indexes(t_data *stacks, int stack)
{
    int index;
    int middle;
    t_stack_node *stack_head;

    index = 0;
    if(stack == STACK_A)
    {
        stack_head = stacks->a;
        middle = stacks->size_a / 2;
    }
    else
    {
        stack_head = stacks->b;
        middle = stacks->size_b / 2;
    }
    while (stack_head)
    {
        stack_head->index = index;
        if (index > middle)
            stack_head->reverse = true;
        else
            stack_head->reverse = false;
        stack_head = stack_head->next;
        index++;
    }
}

void update_indexes(t_data *data)
{
    update_stack_indexes(data, STACK_A);
    update_stack_indexes(data, STACK_B);
}

