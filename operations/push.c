/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:46:05 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/24 17:59:03 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

void    push(t_stack_node **dest, t_stack_node **src)
{
    t_stack_node *to_push;

    to_push = *src;
    if((*src)->next)
        (*src)->next->prev = NULL;
    (*src) = (*src)->next;
    to_push->prev = NULL;
    if(!*dest)
        to_push->next = NULL;
    else
    {
        (*dest)->prev = to_push;
        to_push->next = (*dest);
    }
    (*dest) = to_push;
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}