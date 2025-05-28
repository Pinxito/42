#include "pipex.h"

static int	ft_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free_split(char **tab)
{
	int	i = 0;

	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

static char	*ft_extract_word(char const *s, char c, int i)
{
	int		len = ft_wordlen(s, c, i);
	char	*word = malloc(sizeof(char) * (len + 1));
	int		j;

	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i = 0;
	int		k = 0;

	if (!s)
		return (NULL);
	tab = ft_calloc(sizeof(char *), (ft_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			tab[k] = ft_extract_word(s, c, i);
			if (!tab[k])
			{
				ft_free_split(tab);
				return (NULL);
			}
			k++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab);
}
