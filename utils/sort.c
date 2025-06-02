/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:33:53 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/02 20:11:19 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <unistd.h>

static void update(t_data *stacks)
{
    update_targets(stacks);
    update_indexes(stacks);
    update_costs(stacks);
    update_cheapest(stacks->b);
}

static void	sort_three(t_data *stacks)
{
	t_stack_node	*biggest_node; 

	biggest_node = get_max(stacks->a);
	if (biggest_node == stacks->a) 
		ra(stacks, false); 
	else if (stacks->a->next == biggest_node)
		rra(stacks, false);
	if (stacks->a->val > stacks->a->next->val)
		sa(stacks, false);
}

static void mini_sort(t_data *stacks)
{
    t_stack_node *current;
    while (stacks->size_a > 3)
        pb(stacks, false);
    sort_three(stacks);
    while (stacks->size_b)
    {
        update(stacks);
        current = stacks->b;
        while (current && !current->cheapest)
            current = current->next;
        send_node_to_a(stacks->b, stacks);
    }
    get_min_on_top(stacks);
}
void sort_stacks(t_data *stacks)
{
    t_stack_node *current;
    
    if(stacks->size_a > 5 && !is_sorted(stacks))
    {
        update_final_positions(stacks);
        init_b(stacks);
        while (stacks->size_b)
        {
            update(stacks);
            current = stacks->b;
            while (current && !current->cheapest)
                current = current->next;
            send_node_to_a(current, stacks);
        }
        get_min_on_top(stacks);
    } else if (stacks->size_a <= 5 && stacks->size_a > 2)
        mini_sort(stacks);
    else if (stacks->size_a == 2)
        ra(stacks, false);
}
