/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:33:53 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 23:16:56 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <unistd.h>

void update(t_data *data)
{
    update_targets(data);
    update_indexes(data);
    update_costs(data);
    update_cheapest(data->a);
    update_cheapest(data->b);
}
void sort_stacks(t_data *stacks)
{
    t_stack_node *current;
    if(stacks->size_a > 3)
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
    {
        sort_three(stacks);
    }
    else if (stacks->size_a == 2)
        ra(stacks, false);
}
