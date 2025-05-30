/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:29:11 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:07:05 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

int update_lis(t_data *stacks)
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
    ret = lis_with_sequence(arr, i, &lis);
    a = stacks->a;
    while(a)
    {
        a->in_lis = binary_search(lis, 0, ret, a->val) != -1;
        a = a->next;
    }
    return (ret);
}
void    init_b(t_data *stacks)
{
    t_stack_node *src;
    int lis_size;
    int total;

    lis_size = update_lis(stacks);
    total = stacks->size_a;
    while (stacks->size_a > lis_size)
    {
        src = stacks->a;
        if (!src->in_lis)
        {
            if (src->finalpos > total / 2)
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