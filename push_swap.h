/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:33:36 by amagno-r          #+#    #+#             */
/*   Updated: 2025/05/30 03:48:31 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft/libft.h"
#define STACK_A 0
#define STACK_B 1

typedef struct s_stack_node
{
    int     val;
    int     index;
    int     cost;
    bool    reverse;
    bool    cheapest;
    bool    in_lis;
    int     finalpos;


    struct s_stack_node *target;
    struct s_stack_node *next;
    struct s_stack_node *prev;

}	t_stack_node;

typedef struct s_data
{
    t_stack_node    *a;
    t_stack_node    *b;
    int             size_a;
    int             size_b;
} t_data;

t_stack_node    *get_target_from_b(t_stack_node *src_node, t_stack_node *dest_stack);

// Operation functions
void	sa(t_data *data, bool print);
void	sb(t_data *data, bool print);
void	ss(t_data *data, bool print);

void    ra(t_data *data, bool print);
void    rb(t_data *data, bool print);
void    rr(t_data *data, bool print);

void    rra(t_data *data, bool print);
void    rrb(t_data *data, bool print);
void    rrr(t_data *data, bool print);

void	pa(t_data *data, bool print);
void	pb(t_data *data, bool print);

// Stack utility functions
t_stack_node *get_last(t_stack_node *stack_head);
t_stack_node    *get_min(t_stack_node *stack_head);
t_stack_node    *get_max(t_stack_node *stack_head);
t_stack_node    *find_min(t_stack_node *stack_head);
t_stack_node    *find_max(t_stack_node *stack_head);
int size(t_stack_node *stack_head);
t_stack_node *get(t_stack_node *stack_head, int index);
t_stack_node *append(t_stack_node **stack_head, int val);

// Index and cost functions
void    update_indexes(t_data *data);
void    update_costs(t_data *data);
void    update_cheapest(t_stack_node *stack_head);

// Target calculation functions
void    update_targets(t_data *data);

// Node movement functions
void    send_node_to_b(t_stack_node *src, t_data *data);
void    send_node_to_a(t_stack_node *src, t_data *data);

// Sorting functions
void    sort_stacks(t_data *stacks);
void    get_min_on_top(t_data * data);
bool    is_sorted(t_data *data);

// Initialization and validation functions
void    init_b(t_data *data);
bool    has_duplicates(t_stack_node *a);

// Utility functions
long    ft_atol(char *str);
void    print_stacks(t_data *stacks);

// LIS (Longest Increasing Subsequence) functions
int     lis_with_sequence(int arr[], int n, int **sequence);

// Search and sort functions
int     binary_search(int arr[], int low, int high, int x);
void    quick_sort(int arr[], int low, int high);
int     partition(int arr[], int low, int high);
void    array_swap(int* a, int* b);

// Final positions and LIS update functions
void    update_final_positions(t_data *data);