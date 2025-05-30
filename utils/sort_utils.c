/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 23:02:54 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:12:32 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>
#include <stdlib.h>

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

void update_final_positions(t_data *stacks)
{
    int *arr;
    t_stack_node *a;
    int i;

    i = 0;
    a = stacks->a;
    arr = malloc(sizeof(int) * stacks->size_a);
    while (a)
    {
        arr[i++] = a->val;
        a = a->next;
    }
    quick_sort(arr, 0, stacks->size_a);
    a = stacks->a;
    while(a)
    {
        a->finalpos = binary_search(arr, 0, stacks->size_a, a->val);
        a = a->next;
    }
    free(arr);
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
