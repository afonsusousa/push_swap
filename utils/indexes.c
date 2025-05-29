/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:16:10 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 17:16:24 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../push_swap.h"

static void    update_stack_indexes(t_stack_node *stack_head)
{
    int index;
    int middle;

    index = 0;
    middle = size(stack_head) / 2;
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
    update_stack_indexes(data->a);
    update_stack_indexes(data->b);
}

