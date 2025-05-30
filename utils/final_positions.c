/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:06:42 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:07:23 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../push_swap.h"

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

