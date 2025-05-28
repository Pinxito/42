#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

# define FORMAT    "Format: ./pipex <infile> <cmd1> <cmd2> <outfile>\n"
# define ERR_ARG   "Wrong number of arguments\n"
# define ERR_EXEC  "An error ocurred while executind the command\n"
# define ERR_OPEN  "An error ocurred while opening the file\n"
# define ERR_PIPE  "Problem creating the pipe\n"
# define ERR_PID   "Problem with the fork() function\n"
# define ERR_CMD   "Command not found in any path\n"
# define ERR_SPLIT "An error ocurrend with ft_split\n"

typedef struct s_pipex
{
	pid_t	pid;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*path;
}	t_pipex;

//Pipex Utils
void	ft_exec_cmd(char *cmd, char **envp, t_pipex *p);
void	ft_error(int error);
void	ft_free(char **tab);

//String Utils
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(int number, int size);
char	**ft_split(char const *s, char c);
int ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strjoin(char *s1, char *s2);

#endif
