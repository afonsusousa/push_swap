/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:26:16 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/03 20:08:00 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include <stddef.h>

t_stack_node	*get_last(t_stack_node *stack_head)
{
	if (!stack_head->next)
		return (stack_head);
	while (stack_head)
	{
		if (!stack_head->next)
			break ;
		stack_head = stack_head->next;
	}
	return (stack_head);
}

t_stack_node	*append(t_data *stacks, int val)
{
	t_stack_node	**stack_head;
	t_stack_node	*to_append;
	t_stack_node	*last;

	stack_head = &stacks->a;
	if (!stack_head)
		return (NULL);
	to_append = ft_calloc(sizeof(t_stack_node), 1);
	if (!to_append)
		return (NULL);
	to_append->val = val;
	to_append->next = NULL;
	if (!*stack_head)
	{
		(*stack_head) = to_append;
		to_append->prev = NULL;
	}
	else
	{
		last = get_last(*stack_head);
		last->next = to_append;
		last->next->prev = last;
	}
	stacks->size_a++;
	return (to_append);
}

bool	has_duplicates(t_stack_node *a)
{
	t_stack_node	*current;
	t_stack_node	*checker;

	current = a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->val == checker->val)
				return (true);
			checker = checker->next;
		}
		current = current->next;
	}
	return (false);
}

bool	is_sorted(t_data *data)
{
	t_stack_node	*current;

	if (data->size_b != 0)
		return (false);
	current = data->a;
	while (current && current->next)
	{
		if (current->val > current->next->val)
			return (false);
		current = current->next;
	}
	return (true);
}
