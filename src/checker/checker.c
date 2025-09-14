/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:54:59 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/24 20:53:21 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"
#include <stddef.h>
#include <unistd.h>

t_data	new_data(void)
{
	t_data	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.size_a = 0;
	stacks.size_b = 0;
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_data	stacks;

	stacks = new_data();
	parse_stacks(argc, argv, &stacks);
	parse_op(&stacks);
	if (!is_sorted(&stacks) && !stacks.b && !stacks.size_b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (free_data(&stacks, NULL), 0);
}
