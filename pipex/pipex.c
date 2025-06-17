/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:18:19 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/17 17:56:12 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char **argv, char **envp, t_pipex *p)
{
	if (p->infile < 0)
	{
		close(p->fd[1]);
		exit(1);
	}
	dup2(p->infile, STDIN_FILENO);
	dup2(p->fd[1], STDOUT_FILENO);
	close(p->fd[0]);
	close(p->infile);
	close(p->fd[1]);
	ft_exec_cmd(argv[2], envp, p);
}

static void	ft_parent_process(char **argv, char **envp, t_pipex *p)
{
	if (p->outfile < 0)
	{
		close(p->fd[0]);
		exit(1);
	}
	dup2(p->fd[0], STDIN_FILENO);
	dup2(p->outfile, STDOUT_FILENO);
	close(p->fd[1]);
	close(p->outfile);
	close(p->fd[0]);
	ft_exec_cmd(argv[3], envp, p);
}

static void	setup_pipex(t_pipex *p, char *infile, char *outfile)
{
	p->infile = open(infile, O_RDONLY);
	if (p->infile == -1)
	{
		perror(infile);
		ft_error(1);
	}
	p->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->outfile < 0)
	{
		perror(outfile);
		ft_error(1);
	}
	if (pipe(p->fd) == -1)
		ft_error(2);
}

static pid_t	create_processes(t_pipex *p, char **argv, char **envp)
{
	p->pid = fork();
	if (p->pid == -1)
	{
		close(p->fd[0]);
		close(p->fd[1]);
		ft_error(3);
	}
	if (p->pid == 0)
		ft_child_process(argv, envp, p);
	p->pid2 = fork();
	if (p->pid2 == -1)
	{
		close(p->fd[0]);
		close(p->fd[1]);
		ft_error(3);
	}
	if (p->pid2 == 0)
		ft_parent_process(argv, envp, p);
	close(p->fd[0]);
	close(p->fd[1]);
	return (p->pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc != 5)
		ft_error(6);
	setup_pipex(&p, argv[1], argv[4]);
	create_processes(&p, argv, envp);
	return (handle_exit_code(p.pid, p.pid2));
}
