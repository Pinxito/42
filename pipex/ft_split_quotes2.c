/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:42:49 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/17 22:13:21 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	skip_quoted_word(const char *s, int *i)
{
	char	quote;

	quote = s[*i];
	(*i)++;
	while (s[*i] && !(s[*i] == quote && !is_escaped(s, *i)))
		(*i)++;
	if (s[*i] == quote)
		(*i)++;
}

void	skip_unquoted_word(const char *s, int *i)
{
	while (s[*i] && s[*i] != ' ')
	{
		if (is_quote(s[*i]) && !is_escaped(s, *i))
			break ;
		if (s[*i] == '\\' && s[*i + 1])
			(*i)++;
		(*i)++;
	}
}

int	count_words(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i])
			count++;
		if (is_quote(s[i]) && !is_escaped(s, i))
			skip_quoted_word(s, &i);
		else
			skip_unquoted_word(s, &i);
	}
	return (count);
}

char	**allocate_result(int words)
{
	char	**result;

	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	return (result);
}

int	fill_split_array(const char *s, char **result)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		result[k] = extract_word(s, &i);
		if (!result[k])
		{
			while (k > 0)
				free(result[--k]);
			free(result);
			return (0);
		}
		k++;
	}
	result[k] = NULL;
	return (1);
}
