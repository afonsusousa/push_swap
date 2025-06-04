/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:18:45 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/04 17:57:09 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include "../get_next_line/get_next_line.h"
#include <stdlib.h>

int exec_op(char *op, t_data *stacks)
{
    if(!ft_strncmp(op, "sa\n", 3))
        return (sa(stacks, true), 1);
    if(!ft_strncmp(op, "sb\n", 3))
        return (sb(stacks, true), 1);
    if(!ft_strncmp(op, "ss\n", 3))
        return (ss(stacks, true), 1);
    if(!ft_strncmp(op, "ra\n", 3))
        return (ra(stacks, true), 1);
    if(!ft_strncmp(op, "rb\n", 3))
        return (rb(stacks, true), 1);
    if(!ft_strncmp(op, "rr\n", 3))
        return (rr(stacks, true), 1);
    if(!ft_strncmp(op, "rra\n", 3))
        return (rra(stacks, true), 1);
    if(!ft_strncmp(op, "rrb\n", 3))
        return (rrb(stacks, true), 1);
    if(!ft_strncmp(op, "rrr\n", 3))
        return (rrr(stacks, true), 1);
    if(!ft_strncmp(op, "pa\n", 3))
        return (pa(stacks, true), 1);
    if(!ft_strncmp(op, "pb\n", 3))
        return (pb(stacks, true), 1);
    return (0);
}

int parse_op(t_data *stacks)
{
    char *op;

    op = get_next_line(0);
    while(op)
    {
        if(!exec_op(op, stacks))
        {
            free(op);
            ft_error(stacks, NULL);
            return (0);
        }
        free(op);
        op = get_next_line(0);
    }
    return (1);
}
