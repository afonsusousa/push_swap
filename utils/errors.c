/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:09:02 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/02 18:42:58 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void    free_data(t_data *stacks, char ***nbrs)
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
    free_nbrs(nbrs);
}
void    free_nbrs(char ***nbrs)
{
    char **nbrss;

    if (!nbrs || !*nbrs)
        return;
    nbrss = *nbrs;
    while(nbrss && *nbrss)
    {
        free(*nbrss);
        *nbrss++ = NULL;
    }
    free(*nbrs);
    *nbrs = NULL;
}

void ft_error(t_data *stacks, char ***nbrs)
{
    free_data(stacks, nbrs);
    write(2, "Error\n", 7);
    exit(1);
}