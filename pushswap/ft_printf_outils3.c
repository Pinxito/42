
#include "push_swap.h"

int	ft_counthexlen(unsigned long n)
{
	unsigned long int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_convert_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_convert_ptr(num / 16);
		ft_convert_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

int	ft_putptr(void *ptr)
{
	unsigned int	contador;
	unsigned long	address;

	contador = 0;
	address = (unsigned long)ptr;
	if (address == 0)
	{
		(void)write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		contador += write(1, "0x", 2);
		ft_convert_ptr(address);
		contador += ft_counthexlen(address);
	}
	return (contador);
}

void	ft_convert_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_convert_hex(num / 16, format);
		ft_convert_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_convert_hex(num, format);
	return (ft_counthexlen(num));
}
