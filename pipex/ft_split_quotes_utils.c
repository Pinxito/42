/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:26:39 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/17 20:50:53 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	quoted_word_length(const char *s, int i)
{
	int		len;
	char	quote;

	len = 0;
	quote = s[i];
	i++;
	while (s[i])
	{
		if (s[i] == quote && !is_escaped(s, i))
			break ;
		len++;
		i++;
	}
	return (len);
}

int	unquoted_word_length(const char *s, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != ' ')
	{
		if (is_quote(s[i]) && !is_escaped(s, i))
			break ;
		if (s[i] == '\\' && s[i + 1])
		{
			i++;
			len++;
		}
		len++;
		i++;
	}
	return (len);
}

char	*extract_quoted_word(const char *s, int *i)
{
	int		j;
	char	quote;
	char	*word;
	int		len;

	j = 0;
	quote = s[*i];
	(*i)++;
	len = word_length(s, *i - 1);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[*i] && !(s[*i] == quote && !is_escaped(s, *i)))
	{
		if (s[*i] == '\\' && s[*i + 1])
			(*i)++;
		word[j++] = s[*i];
		(*i)++;
	}
	if (s[*i] == quote)
		(*i)++;
	word[j] = '\0';
	return (word);
}

char	*extract_unquoted_word(const char *s, int *i)
{
	int		j;
	char	*word;
	int		len;

	j = 0;
	len = word_length(s, *i);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[*i] && s[*i] != ' ')
	{
		if (is_quote(s[*i]) && !is_escaped(s, *i))
			break ;
		if (s[*i] == '\\' && s[*i + 1])
			(*i)++;
		word[j++] = s[*i];
		(*i)++;
	}
	word[j] = '\0';
	return (word);
}

char	*extract_word(const char *s, int *i)
{
	if (is_quote(s[*i]) && !is_escaped(s, *i))
		return (extract_quoted_word(s, i));
	else
		return (extract_unquoted_word(s, i));
}
