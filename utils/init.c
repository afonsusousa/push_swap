/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:29:11 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 04:41:12 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

static int optimal_threshold(t_data *stacks)
{
    t_stack_node *a;
    int non_lis_count = 0;
    int high_pos_count = 0;
    int mid_pos_count = 0;
    int low_pos_count = 0;
    int total = stacks->size_a;
    
    a = stacks->a;
    while (a)
    {
        if (!a->in_lis)
        {
            non_lis_count++;
            if (a->finalpos >= total * 2 / 3)
                high_pos_count++;
            else if (a->finalpos >= total / 3)
                mid_pos_count++;
            else
                low_pos_count++;
        }
        a = a->next;
    }
    if (non_lis_count == 0)
        return total / 2;
    if (high_pos_count > mid_pos_count + low_pos_count)
        return (total * 40) / 100;
    if (low_pos_count > high_pos_count + mid_pos_count)
        return (total * 60) / 100;
    int balance_ratio = (high_pos_count * 100) / non_lis_count;
    if (balance_ratio > 60)
        return (total * 42) / 100;
    else if (balance_ratio > 40)
        return (total * 45) / 100;
    else
        return (total * 55) / 100;
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
    a = stacks->a;
    while(a)
    {
        a->in_lis = binary_search(lis, 0, ret, a->val) != -1;
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