#include "push_swap.h"
#include <stdlib.h>

// Función que verifica si un carácter es un delimitador.
static int ft_sepa(char c, char delim)
{
    return (c == delim);
}

// Función que cuenta cuántas palabras hay en la cadena 's' que no están separadas por el delimitador 'c'.
static int palabras(char const *s, char c)
{
    int palabra = 0;
    int in_word = 0;

    while (*s)
    {
        if (ft_sepa(*s, c))
        {
            in_word = 0; // Estamos en un delimitador
        }
        else if (!in_word)
        {
            in_word = 1; // Encontramos el inicio de una palabra
            palabra++;
        }
        s++; // Avanzar al siguiente carácter
    }

    return (palabra);
}

// Función que calcula la longitud de una palabra hasta encontrar un delimitador.
static size_t talla(char const *s, char c)
{
    size_t len = 0;
    while (s[len] && !ft_sepa(s[len], c))
        len++;
    return (len);
}

// Función que reserva y copia una palabra desde 's' hasta el siguiente delimitador.
static char *poner(char const *s, char c)
{
    size_t len = talla(s, c);
    char *palabra = malloc((len + 1) * sizeof(char));
    if (!palabra)
        return (NULL);

    size_t i = 0;
    while (i < len)
    {
        palabra[i] = s[i];
        i++;
    }
    palabra[i] = '\0';
    return (palabra);
}

// Función principal que separa la cadena 's' en substrings, usando el delimitador 'c'.
char **ft_split(char const *s, char c)
{
    if (!s) 
        return (NULL); // Si la cadena es NULL, devolvemos NULL

    int num_palabras = palabras(s, c); // Contamos cuántas palabras hay en 's'
    char **result = malloc((num_palabras + 1) * sizeof(char *)); // Reservamos memoria para el array de palabras

    if (!result) 
        return (NULL); // Si falla la reserva de memoria, devolvemos NULL

    int i = 0;
    while (i < num_palabras)
    {
        // Saltamos los delimitadores antes de la siguiente palabra
        while (*s && ft_sepa(*s, c))
            s++;

        // Reservamos y copiamos la palabra
        result[i] = poner(s, c);
        if (!result[i]) 
        {
            // Si la reserva de alguna palabra falla, liberamos la memoria ya reservada
            while (i > 0)
            {
                free(result[--i]);
            }
            free(result);
            return (NULL);
        }

        i++;

        // Avanzamos al siguiente delimitador para buscar la siguiente palabra
        while (*s && !ft_sepa(*s, c))
            s++;
    }

    result[i] = NULL; // Terminamos el array con NULL
    return (result);
}

void free_split(char **split)
{
    int i = 0;

    if (!split)
        return;
    while (split[i])
        free(split[i++]); // Liberar cada string individualmente
    free(split); // Liberar el array de punteros
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int    main(int ac, char **av)
{
	int		i;
	char	**ex;
	

	if (ac == 3)
	{
		ex = ft_split(av[1], av[2]);
	   
		
		i = 0;
		while (ex[i])
		{
			printf("%s\n", ex[i]);
		   
			i++;
		}
	}
	return (0);
}
*/