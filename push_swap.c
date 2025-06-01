/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 01:34:27 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/01 20:44:05 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int main(int argc, char **argv)
{
  
    t_data stacks;
    long value;

    stacks.a = NULL;
    stacks.b = NULL;
    stacks.size_a = 0;
    stacks.size_b = 0;
    int i;

    i = 1;
    char **nbrs;
    (void) argc;
    while (i < argc)
    {
        nbrs = ft_split(argv[i], ' ');
        if(!nbrs)
            free_data(&stacks);
        while (*nbrs)
        {
            value = ft_atol(*nbrs++);
            if(value == ATOL_ERROR || !append(&stacks, value) 
                || has_duplicates(stacks.a))
                ft_error(&stacks);
        }
        i++;
    }
    sort_stacks(&stacks);
}
