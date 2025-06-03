/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:46:05 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/02 22:07:42 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*to_push;

	to_push = *src;
	if (!*src)
		return ;
	if ((*src)->next)
		(*src)->next->prev = NULL;
	(*src) = (*src)->next;
	to_push->prev = NULL;
	if (!*dest)
		to_push->next = NULL;
	else
	{
		(*dest)->prev = to_push;
		to_push->next = (*dest);
	}
	(*dest) = to_push;
}

void	pa(t_data *stacks, bool print)
{
	push(&stacks->a, &stacks->b);
	stacks->size_b--;
	stacks->size_a++;
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_data *stacks, bool print)
{
	push(&stacks->b, &stacks->a);
	stacks->size_a--;
	stacks->size_b++;
	if (!print)
		ft_printf("pb\n");
}
