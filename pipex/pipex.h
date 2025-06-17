/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:15:36 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/17 21:21:15 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define FORMAT "Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n"
# define ERR_ARG "Wrong number of arguments\n"
# define ERR_EXEC "An error occurred while executing the command\n"
# define ERR_OPEN "An error occurred while opening the file\n"
# define ERR_PIPE "Problem creating the pipe\n"
# define ERR_PID "Problem with the fork() function\n"
# define ERR_CMD "Command not found in any path\n"
# define ERR_SPLIT "An error occurred with ft_split\n"

typedef struct s_pipex
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*path;
}			t_pipex;

// Pipex Utils
void		ft_exec_cmd(char *cmd, char **envp, t_pipex *p);
void		ft_error(int error);
void		ft_free(char **tab);
int			handle_exit_code(pid_t pid1, pid_t pid2);
void		ft_find_path(char *cmd, char **envp, t_pipex *p);
int			contains_quotes(char *cmd);
char		**ft_split_with_quotes(const char *s);
// String Utils
void		ft_putstr_fd(char *s, int fd);
void		*ft_calloc(int number, int size);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, int n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);
// split
int			is_quote(char c);
int			is_escaped(const char *s, int pos);
int			word_length(const char *s, int i);
int			quoted_word_length(const char *s, int i);
int			unquoted_word_length(const char *s, int i);
char		*extract_quoted_word(const char *s, int *i);
char		*extract_unquoted_word(const char *s, int *i);
char		*extract_word(const char *s, int *i);
void		skip_quoted_word(const char *s, int *i);
void		skip_unquoted_word(const char *s, int *i);
int			count_words(const char *s);
char		**build_split_array(const char *s, int words);
int			fill_split_array(const char *s, char **result);
char		**allocate_result(int words);
char		**ft_split_with_quotes(const char *s);

#endif
