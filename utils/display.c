/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:07:50 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/24 18:27:31 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int max_size(t_stack_node *stack_head_a, t_stack_node *stack_head_b)
{
    int asize;
    int bsize;

    asize = size(stack_head_a);
    bsize = size(stack_head_b);
    if(asize > bsize)
        return (asize);
    return (bsize);
}
void    print_stacks(t_stack_node *stack_head_a, t_stack_node *stack_head_b)
{
    int asize;
    int bsize;
    int print_size;
    int i;

    i = 0;
    asize = size(stack_head_a);
    bsize = size(stack_head_b);
    if (asize > bsize)
        print_size = asize;
    else
        print_size = bsize;
    printf("");
    while (i < print_size)
    {
        if(i > asize)
            printf("       %7d", get(stack_head_b, i)->val);
        else if (i > bsize)
            printf("%-7d       ", get(stack_head_a, i)->val);
        else
            printf("%-7d%7d", get(stack_head_a, i)->val, get(stack_head_b, i)->val);
        i++;
    }
}
