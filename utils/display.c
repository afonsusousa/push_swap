/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:07:50 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/29 04:37:47 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    print_stacks(t_data *stacks)
{
    t_stack_node *a_node;
    t_stack_node *b_node;

    ft_printf("  Stack A   Stack B\n");
    ft_printf("  -------   -------\n");
    
    a_node = stacks->a;
    b_node = stacks->b;
    
    while (a_node || b_node)
    {
        if (a_node && b_node)
            ft_printf("%8d %8d\n", a_node->val, b_node->val);
        else if (a_node && !b_node)
            ft_printf("%8d         \n", a_node->val);
        else if (!a_node && b_node)
            ft_printf("         %8d\n", b_node->val);
            
        if (a_node)
            a_node = a_node->next;
        if (b_node)
            b_node = b_node->next;
    }
    ft_printf("  -------   -------\n");
    ft_printf("     A         B\n\n"); 
}
