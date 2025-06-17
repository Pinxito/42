/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:29:00 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/17 21:10:39 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	is_escaped(const char *s, int pos)
{
	int	count;

	count = 0;
	pos--;
	while (pos >= 0 && s[pos] == '\\')
	{
		count++;
		pos--;
	}
	return (count % 2 == 1);
}

int	word_length(const char *s, int i)
{
	if (is_quote(s[i]) && !is_escaped(s, i))
		return (quoted_word_length(s, i));
	else
		return (unquoted_word_length(s, i));
}

char	**build_split_array(const char *s, int words)
{
	char	**result;

	result = allocate_result(words);
	if (!result)
		return (NULL);
	if (!fill_split_array(s, result))
		return (NULL);
	return (result);
}

char	**ft_split_with_quotes(const char *s)
{
	int		words;
	int		i;
	char	**empty_result;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] == ' ')
		i++;
	words = count_words(s + i);
	if (words == 0)
	{
		empty_result = malloc(sizeof(char *));
		if (!empty_result)
			return (NULL);
		empty_result[0] = NULL;
		return (empty_result);
	}
	return (build_split_array(s + i, words));
}
