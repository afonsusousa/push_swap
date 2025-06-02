/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:36:22 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/02 22:12:23 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	array_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
			array_swap(&arr[++i], &arr[j]);
		j++;
	}
	array_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

int	binary_search(int arr[], int low, int high, int x)
{
	int	mid;

	if (high >= low && low >= 0)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == x)
			return (mid);
		if (arr[mid] > x)
			return (binary_search(arr, low, mid - 1, x));
		return (binary_search(arr, mid + 1, high, x));
	}
	return (-1);
}
