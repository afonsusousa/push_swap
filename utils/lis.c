/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:09:23 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/01 20:21:04 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../push_swap.h"

static void initialize_arrays(int *lis, int *parent, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        lis[i] = 1;
        parent[i] = -1;
        i++;
    }
}

static void compute_lis_values(int arr[], int *lis, int *parent, int n)
{
    int i;
    int j;

    i = 0;
    while (++i < n)
    {
        j = -1;
        while (++j < i)
        { 
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
                parent[i] = j;
            }
        }
    }
}

static void find_max_lis(int *lis, int n, int *max_length, int *max_index)
{
    int i;

    *max_length = lis[0];
    *max_index = 0;
    i = 0;
    while (++i < n)
    {
        if (lis[i] > *max_length)
        {
            *max_length = lis[i];
            *max_index = i;
        }
    }
}

static void reconstruct_sequence(int arr[], int *parent, int max_index, int max_length, int *sequence)
{
    int i;
    int j;

    i = max_index;
    j = max_length;
    while (i != -1)
    {
        sequence[--j] = arr[i];
        i = parent[i];
    }
}

int lis_with_sequence(int arr[], int n, int **sequence)
{
    int *lis, *parent;
    int max_length, max_index;

    if (n == 0)
        return (0);
    lis = (int *)malloc(n * sizeof(int));
    parent = (int *)malloc(n * sizeof(int));
    if (!lis || !parent)
        return (0);
    initialize_arrays(lis, parent, n);
    compute_lis_values(arr, lis, parent, n);
    find_max_lis(lis, n, &max_length, &max_index);
    *sequence = (int *)malloc(max_length * sizeof(int));
    if (!*sequence)
        return (free(lis), free(parent), -1);
    reconstruct_sequence(arr, parent, max_index, max_length, *sequence);
    return (free(lis), free(parent), max_length);
}

