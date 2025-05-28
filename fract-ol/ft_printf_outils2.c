/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:40:48 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 02:40:50 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_countuilen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_convert_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_countuilen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int	ft_uitoa(unsigned int n)
{
	char		*escrito;
	int			talla;

	escrito = ft_convert_unsigned(n);
	if (!escrito)
		return (0);
	talla = ft_strlen(escrito);
	ft_putstr(escrito);
	free(escrito);
	return (talla);
}
