/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:17:02 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/17 19:49:24 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_parse_cmd(char *cmd)
{
	char	**cmd_list;

	if (!cmd)
		ft_error(5);
	if (contains_quotes(cmd))
		cmd_list = ft_split_with_quotes(cmd);
	else
		cmd_list = ft_split(cmd, ' ');
	if (!cmd_list)
		ft_error(5);
	if (!cmd_list[0] || cmd_list[0][0] == '\0')
	{
		ft_free(cmd_list);
		ft_error(0);
	}
	return (cmd_list);
}

char	**ft_prepare_cmd(char *cmd, char **envp, t_pipex *p)
{
	char	**cmd_list;

	cmd_list = ft_parse_cmd(cmd);
	ft_find_path(cmd_list[0], envp, p);
	if (!p->path && access(cmd_list[0], F_OK | X_OK) == 0)
		p->path = ft_strdup(cmd_list[0]);
	if (!p->path)
	{
		ft_free(cmd_list);
		ft_putstr_fd(ERR_CMD, 2);
		exit(127);
	}
	return (cmd_list);
}

void	ft_exec_cmd(char *cmd, char **envp, t_pipex *p)
{
	char	**cmd_list;

	cmd_list = ft_prepare_cmd(cmd, envp, p);
	execve(p->path, cmd_list, envp);
	ft_free(cmd_list);
	if (p->path != cmd_list[0])
		free(p->path);
	if (p->infile >= 0)
		close(p->infile);
	if (p->outfile >= 0)
		close(p->outfile);
	if (p->fd[0] >= 0)
		close(p->fd[0]);
	if (p->fd[1] >= 0)
		close(p->fd[1]);
	ft_error(0);
}

void	ft_error(int error)
{
	if (error == 0)
	{
		ft_putstr_fd(ERR_EXEC, 2);
		exit(127);
	}
	else if (error == 1)
		ft_putstr_fd(ERR_OPEN, 2);
	else if (error == 2)
		ft_putstr_fd(ERR_PIPE, 2);
	else if (error == 3)
		ft_putstr_fd(ERR_PID, 2);
	else if (error == 4)
		ft_putstr_fd(ERR_CMD, 2);
	else if (error == 5)
		ft_putstr_fd(ERR_SPLIT, 2);
	else if (error == 6)
	{
		ft_putstr_fd(ERR_ARG, 2);
		ft_putstr_fd(FORMAT, 2);
	}
	exit(EXIT_FAILURE);
}

int	contains_quotes(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '\'' || *cmd == '"')
			return (1);
		cmd++;
	}
	return (0);
}
