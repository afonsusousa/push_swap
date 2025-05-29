/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 23:02:54 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 18:14:54 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

t_stack_node    *get_min(t_stack_node *stack_head)
{
    long min;
    t_stack_node *min_node;

    min = LONG_MAX;
    min_node = NULL;
    while(stack_head)
    {
        if(stack_head->val < min)
        {
            min = stack_head->val;
            min_node = stack_head;
        }
        stack_head = stack_head->next;
    }
    return (min_node);
}

t_stack_node    *get_max(t_stack_node *stack_head)
{
    long max;
    t_stack_node *max_node;

    max = LONG_MIN;
    max_node = NULL;
    while(stack_head)
    {
        if(stack_head->val > max)
        {
            max = stack_head->val;
            max_node = stack_head;
        }
        stack_head = stack_head->next;
    }
    return (max_node);
}
bool    is_sorted(t_data *data)
{
    t_stack_node *a;

    a = data->a;
    if (!a)
        return (false);
    while(a->next)
    {
        if(a->val > a->next->val)
        {
           // ft_printf("failed at %d", a->val);
            return (false);
        }
        a = a->next;
    }
    return (true);
}

void    get_min_on_top(t_data * data)
{
    t_stack_node *min;

    min = get_min(data->a);
    update_indexes(data);
    while(data->a != min)
    {
        if(!min->reverse)
            ra(data, false);
        else
            rra(data, false);
    }
}
void	sort_three(t_data *data)
{
	t_stack_node	*biggest_node; 

	biggest_node = get_max(data->a);
	if (biggest_node == data->a) 
		ra(data, false); 
	else if (data->a->next == biggest_node)
		rra(data, false);
	if (data->a->val > data->a->next->val)
		sa(data, false);
}

