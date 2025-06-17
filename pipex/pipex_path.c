/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:05:55 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/17 18:09:26 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

static char	*ft_build_cmd_path(char *dir, char *cmd)
{
	char	*append;
	char	*cmd_path;

	append = ft_strjoin(dir, "/");
	if (!append)
		return (NULL);
	cmd_path = ft_strjoin(append, cmd);
	free(append);
	return (cmd_path);
}

static char	*ft_find_valid_path(char **paths, char *cmd)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_build_cmd_path(paths[i], cmd);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

void	ft_find_path(char *cmd, char **envp, t_pipex *p)
{
	char	**paths;
	char	*cmd_path;

	paths = ft_get_paths(envp);
	if (!paths)
	{
		p->path = NULL;
		return ;
	}
	cmd_path = ft_find_valid_path(paths, cmd);
	ft_free(paths);
	p->path = cmd_path;
}
