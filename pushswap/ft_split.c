/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:45:18 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/29 16:49:19 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sepa(char c, char delim)
{
	return (c == delim);
}

static int	palabras(char const *s, char c)
{
	int	palabra;
	int	in_word;

	palabra = 0;
	in_word = 0;
	while (*s)
	{
		if (ft_sepa(*s, c))
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			palabra++;
		}
		s++;
	}
	return (palabra);
}

// Función que calcula la longitud de una palabra hasta encontrar un delimitador.
static size_t	talla(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && !ft_sepa(s[len], c))
		len++;
	return (len);
}

// Función que reserva y copia una palabra desde 's' hasta el siguiente delimitador.
static char	*poner(char const *s, char c)
{
	size_t	len;
	char	*palabra;
	size_t	i;

	len = talla(s, c);
	palabra = malloc((len + 1) * sizeof(char));
	if (!palabra)
		return (NULL);
	i = 0;
	while (i < len)
	{
		palabra[i] = s[i];
		i++;
	}
	palabra[i] = '\0';
	return (palabra);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		num_palabras;
	char	**result;

	if (!s)
		return (NULL);
	num_palabras = palabras(s, c);
	result = malloc((num_palabras + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < num_palabras)
	{
		while (*s && ft_sepa(*s, c))
			s++;
		result[i] = poner(s, c);
		if (!result[i])
		{
			while (i > 0)
			{
				free(result[--i]);
			}
			free(result);
			return (NULL);
		}
		i++;
		while (*s && !ft_sepa(*s, c))
			s++;
	}
	result[i] = NULL;
	return (result);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}
