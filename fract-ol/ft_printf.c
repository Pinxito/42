/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 01:58:08 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 02:40:24 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_format(va_list lista, const char *format)
{
	int	contador;

	contador = 0;
	if (*format == 'c')
		contador += ft_putchar(va_arg(lista, int));
	else if (*format == 's')
		contador += ft_putstr(va_arg(lista, char *));
	else if (*format == 'p')
		contador += ft_putptr(va_arg(lista, void *));
	else if (*format == 'd' || *format == 'i')
		contador += ft_itoa(va_arg(lista, int));
	else if (*format == 'u')
		contador += ft_uitoa(va_arg(lista, unsigned int));
	else if (*format == 'x' || *format == 'X')
		contador += ft_puthex(va_arg(lista, unsigned int), *format);
	else if (*format == '%')
		contador += ft_putchar('%');
	return (contador);
}

int	ft_printf(const char *format, ...)
{
	va_list	lista;
	int		contador;

	contador = 0;
	va_start(lista, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			contador += ft_format(lista, (char *)format);
		}
		else
			contador += ft_putchar(*format);
		format++;
	}
	va_end(lista);
	return (contador);
}
