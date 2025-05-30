/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:35:14 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/29 16:35:16 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countlen(long int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_convert(long int n, int is_negative)
{
	int		len;
	char	*str;

	len = ft_countlen(n) + is_negative;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (is_negative)
		str[0] = '-';
	if (n < 0)
		n = -n;
	while (len > is_negative)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int	ft_itoa(int n)
{
	long int	nb;
	char		*num;
	int			talla;

	nb = n;
	num = ft_convert(nb, (nb < 0));
	if (!num)
		return (0);
	talla = ft_strlen(num);
	ft_putstr(num);
	free(num);
	return (talla);
}
