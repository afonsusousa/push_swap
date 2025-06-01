/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:09:02 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/01 20:29:35 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void    free_data(t_data *stacks)
{
    t_stack_node *a;
    t_stack_node *b;
    t_stack_node *iter;

    a = stacks->a;
    b = stacks->b;
    while (a)
    {
        iter = a->next;
        free(a);
        a = iter;
    }
    while (b)
    {
        iter = b->next;
        free(b);
        b = iter;
    }
    stacks->a = NULL;
    stacks->b = NULL;
}

void ft_error(t_data *stacks)
{
    free_data(stacks);
    write(2, "Error\n", 7);
    exit(1);
}