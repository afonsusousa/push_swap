/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:43:09 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 17:44:47 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

void set_cost(t_stack_node *current, t_data *data, int stack)
{
    int stack_size = (!stack * data->size_a) + (stack * data->size_b);
    if(!current->reverse)
        current->cost = current->index;
    else
        current->cost = stack_size - current->index;
}

void update_costs(t_data *data)
{
    t_stack_node *a;
    t_stack_node *b;

    a = data->a;
    b = data->b;
    while(a)
    {
        set_cost(a, data, STACK_A);
        a = a->next;
    }
    while (b)
    {
        set_cost(b, data, STACK_B);
        b = b->next;
    }
    update_indexes(data);
    update_targets(data);
    
}
void   update_cheapest(t_stack_node *stack_head)
{
    t_stack_node *current;
    t_stack_node *cheapest;
    int          mincost;

    mincost = INT_MAX;
    current = stack_head;
    while(current)
    {
        current->cheapest = false;
        if(current->cost + current->target->cost < mincost)
        {
            mincost = current->cost + current->target->cost;
            cheapest = current;
        }
        current = current->next;
    }
    cheapest->cheapest = true;
}