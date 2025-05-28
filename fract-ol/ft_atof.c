/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 01:37:02 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 14:00:01 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_parse_decimal(const char *str, int *i, int *err)
{
	double	dec;
	double	result;

	dec = 0.1;
	result = 0.0;
	(*i)++;
	if (str[*i] < '0' || str[*i] > '9')
	{
		*err = 1;
		return (0.0);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result += (str[*i] - '0') * dec;
		dec *= 0.1;
		(*i)++;
	}
	return (result);
}

static int	ft_parse_sign_and_integer(const char *str, int *i, double *result,
		int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (str[*i] < '0' || str[*i] > '9')
		return (1);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (0);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		i;
	int		err;

	result = 0.0;
	sign = 1;
	i = 0;
	err = 0;
	if (ft_parse_sign_and_integer(str, &i, &result, &sign))
	{
		ft_printf("Error: \"%s\" not a valid number\n", str);
		return (NAN);
	}
	if (str[i] == '.')
		result += ft_parse_decimal(str, &i, &err);
	if (err || str[i] != '\0')
	{
		ft_printf("Error: \"%s\" not a valid number\n", str);
		return (NAN);
	}
	return (result * sign);
}
