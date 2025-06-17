/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 04:34:30 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/17 17:56:29 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	handle_exit_code(pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0)
		return (WEXITSTATUS(status1));
	else if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	else if (WIFSIGNALED(status1))
		return (128 + WTERMSIG(status1));
	else if (WIFSIGNALED(status2))
		return (128 + WTERMSIG(status2));
	return (1);
}
