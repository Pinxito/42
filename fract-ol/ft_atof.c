#include "fractol.h" // para ft_printf

static double	ft_parse_decimal(const char *str, int *i, int *err)
{
	double	dec = 0.1;
	double	result = 0.0;

	(*i)++; // saltar el punto decimal

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

static int	ft_parse_sign_and_integer(const char *str, int *i, double *result, int *sign)
{
	// saltar espacios
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;

	// signo
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}

	// debe haber al menos un dígito antes del decimal
	if (str[*i] < '0' || str[*i] > '9')
		return (1); // error

	// parte entera
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (0); // sin error
}

double	ft_atof(const char *str)
{
	double	result = 0.0;
	int		sign = 1;
	int		i = 0;
	int		err = 0;

	if (ft_parse_sign_and_integer(str, &i, &result, &sign))
	{
		ft_printf("Error: \"%s\" no es un número válido\n", str);
		return (NAN);
	}

	if (str[i] == '.')
		result += ft_parse_decimal(str, &i, &err);

	if (err || str[i] != '\0')
	{
		ft_printf("Error: \"%s\" no es un número válido\n", str);
		return (NAN);
	}

	return (result * sign);
}
