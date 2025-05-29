/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 01:34:27 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 03:48:08 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int main(int argc, char **argv)
{
  
    t_data stacks;

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
        while (*nbrs)
        {
            append(&stacks.a, ft_atol(*nbrs));
            stacks.size_a++;
            nbrs++;
        }
        i++;
    }
    sort_stacks(&stacks);
}