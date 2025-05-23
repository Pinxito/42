static double	ft_parse_decimal(const char *str, int *i)
{
	double	dec; 
	double	result; 
    
    result = 0.0;
    dec = 0.1;
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result += (str[*i] - '0') * dec;
		dec *= 0.1;
		(*i)++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result; 
	int		sign; 
	int		i; 

    result = 0.0;
    sign = 1;
    i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		result += ft_parse_decimal(str, &i);
	return (result * sign);
}
#include<stdio.h>
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Uso: %s <numero>\n", argv[0]);
		return (1);
	}
	double result = ft_atof(argv[1]);
	printf("Resultado: %f\n", result);
	return (0);
}