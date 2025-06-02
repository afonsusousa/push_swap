/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:29:11 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/02 18:35:27 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

static int optimal_threshold(t_data *stacks)
{
    t_stack_node *a = stacks->a;
    int high_weight = 0, low_weight = 0, pos = 0;
    int total = stacks->size_a;
    
    while (a)
    {
        if (!a->in_lis)
        {
            int weight = total - pos;
            if (a->finalpos >= total * 2 / 3)
                high_weight += weight;
            else if (a->finalpos < total / 3)
                low_weight += weight;
        }
        a = a->next;
        pos++;
    }
    int balance = (high_weight - low_weight) * 10 / (high_weight + low_weight + 1);
    return total * (50 + (balance > 0 ? 5 : -5)) / 100;
}

static int update_lis(t_data *stacks)
{
    int i;
    int ret;
    int *lis;
    int *arr;
    t_stack_node *a;

    i = 0;
    a = stacks->a;
    arr = malloc(sizeof(int) * stacks->size_a);
    while (a)
    {
        arr[i++] = a->val;
        a = a->next;
    }
    ret = lis_with_sequence(arr, stacks->size_a, &lis);
    if(!ret)
        ft_error(stacks, NULL);
    a = stacks->a;
    while(a)
    {
        a->in_lis = binary_search(lis, 0, ret - 1, a->val) != -1;
        a = a->next;
    }
    return (free(lis), free(arr), ret);
}
void    init_b(t_data *stacks)
{
    t_stack_node *src;
    int lis_size;
    int threshold;

    lis_size = update_lis(stacks);
    threshold = optimal_threshold(stacks);
    while (stacks->size_a > lis_size)
    {
        src = stacks->a;
        if (!src->in_lis)
        {
            if (src->finalpos > threshold)
            {
                pb(stacks, false);
                rb(stacks, false);
            }
            else
                pb(stacks, false); 
        }
        else
            ra(stacks, false);
    }
}
bool has_duplicates(t_stack_node *a)
{
    t_stack_node *iter;

    while(a)
    {
        iter = a->next;
        while (iter)
        {
            if (iter->val == a->val)
                return (true);
            iter = iter->next;
        }
        a = a->next;
    }
    return (false);
}