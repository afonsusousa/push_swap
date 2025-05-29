/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:29:11 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 18:07:11 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

void    init_b(t_data *data)
{
    t_stack_node *src;

    pb(data, false);
    pb(data, false);
    while (data->size_a > 3)
    {
        update(data);
        src = data->a;
        while (src && !src->cheapest)
            src = src->next;
        send_node_to_b(src, data);
    }
}
bool has_duplicates(t_stack_node *a)
{
    t_stack_node *iter;

    while(a)
    {
        iter = a->next;
        while (iter)
        {
            if (iter->val == a->val)
                return (true);
            iter = iter->next;
        }
        a = a->next;
    }
    return (false);
}