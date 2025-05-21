#include "fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	
	(void)write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		(void)write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		ft_putchar(*str);
		str++;
		i++;
	}
	return (i);
}
