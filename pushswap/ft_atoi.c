/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:39:26 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/30 13:02:55 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_sign(const char *str, int *sign, int *i)
{
	*sign = 1;
	*i = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (!str[*i])
		return (0);
	return (1);
}

int	ft_atoi(const char *str, int *out)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	if (!handle_sign(str, &sign, &i))
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && - result < INT_MIN))
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}
