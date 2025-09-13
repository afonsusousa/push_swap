/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:12:25 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/03 20:06:10 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void parse_stacks(int argc, char **argv, t_data *stacks)
{
    char **nbrs;
    int i;
    int j;
    long value;

    i = 1;
	if (argc == 1)
		ft_error(stacks, &nbrs);
    while (i < argc)
	{
		j = 0;
		nbrs = ft_split(argv[i++], ' ');
		if (!nbrs || !*nbrs)
			ft_error(stacks, &nbrs);
		while (nbrs[j])
		{
			value = ft_atol(nbrs[j++]);
			if (value == ATOL_ERROR || !append(stacks, value)
				|| has_duplicates(stacks->a))
				ft_error(stacks, &nbrs);
		}
		free_nbrs(&nbrs);
	}
}