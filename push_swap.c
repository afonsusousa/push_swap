/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 01:34:27 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/02 18:44:01 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

t_data new_data()
{
    t_data stacks;
    stacks.a = NULL;
    stacks.b = NULL;
    stacks.size_a = 0;
    stacks.size_b = 0;
    return (stacks);
}
int main(int argc, char **argv)
{
  
    int i;
    int j;
    char **nbrs;
    t_data stacks;
    long value;

    i = 1;
    stacks = new_data();
    while (i < argc)
    {
        j = 0;
        nbrs = ft_split(argv[i++], ' ');
        if(!nbrs || !*nbrs)
            ft_error(&stacks, &nbrs);
        while (nbrs[j])
        {
            value = ft_atol(nbrs[j++]);
            if(value == ATOL_ERROR || !append(&stacks, value) 
                || has_duplicates(stacks.a))
                ft_error(&stacks, &nbrs);
        }
        free_nbrs(&nbrs);
    }
    return(sort_stacks(&stacks), free_data(&stacks, NULL), 0);
}
