/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:29:11 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 23:03:26 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

int update_lis(t_data *data)
{
    int i;
    int ret;
    int *lis;
    int *arr;
    t_stack_node *a;

    i = 0;
    a = data->a;
    arr = malloc(sizeof(int) * data->size_a);
    while (a)
    {
        arr[i++] = a->val;
        a = a->next;
    }
    ret = lis_with_sequence(arr, i, &lis);
    a = data->a;
    while(a)
    {
        a->in_lis = binary_search(lis, 0, ret, a->val) != -1;
        a = a->next;
    }
    return (ret);
}
void    init_b(t_data *data)
{
    t_stack_node *src;
    int lis_size;
    int total;

    lis_size = update_lis(data);
    total = data->size_a;
    while (data->size_a > lis_size)
    {
        src = data->a;
        if (!src->in_lis)
        {
            if (src->finalpos > total / 2)
            {
                pb(data, false);
                rb(data, false);
            }
            else
                pb(data, false); 
        }
        else
            ra(data, false);
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