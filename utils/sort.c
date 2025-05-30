/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:33:53 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:03:51 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <unistd.h>

static void update(t_data *data)
{
    update_targets(data);
    update_indexes(data);
    update_costs(data);
    update_cheapest(data->b);
}
static void	sort_three(t_data *data)
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
void sort_stacks(t_data *stacks)
{
    t_stack_node *current;
    
    if(stacks->size_a > 3 && !is_sorted(stacks))
    {
        update_final_positions(stacks);
        init_b(stacks);
        sort_three(stacks);
        while (stacks->size_b)
        {
            update(stacks);
            current = stacks->b;
            while (current && !current->cheapest)
                current = current->next;
            send_node_to_a(current, stacks);
        }
        get_min_on_top(stacks);
    }
    if (stacks->size_a == 3)
        sort_three(stacks);
    else if (stacks->size_a == 2)
        ra(stacks, false);
}
