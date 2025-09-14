/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:41:20 by amagno-r          #+#    #+#             */
/*   Updated: 2025/06/03 19:16:52 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

long	ft_atol(char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		sign = (-1 * (*(str++) == '-'));
	if (*str < '0' || *str > '9')
		return (ATOL_ERROR);
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + (*(str++) - '0');
	if (*str || (sign == 1) * (ret * sign) > INT_MAX || (sign == -1) * (ret
			* sign) < INT_MIN)
		return (ATOL_ERROR);
	return (ret * sign);
}
