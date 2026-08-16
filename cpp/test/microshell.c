#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void    ft_putstr(char *str)
{
    while (*str)
        write(2, str++, 1);
}

int ft_cd(int ac, char *dir)
{
    if (ac != 2)
        return (ft_putstr("error: cd: bad arguments\n"), 1);
    if (chdir(dir) == -1)
        return (ft_putstr("error: cd: cannot change directory to "), ft_putstr(dir), ft_putstr("\n"), 1);
    return (0);
}

void    ft_setpipe(int has_pipe, int *fd, int end)
{
    if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        ft_putstr("error: fatal\n"), exit(1);
}

int ft_exec(int ac, char *av[], char *env[], int has_pipe)
{
    int fd[2];
    int status;
    int pid;
    char *cmd = av[0];

    if (!has_pipe && !strcmp(cmd, "cd"))
        return (ft_cd(ac, av[1]));
    if ((has_pipe && pipe(fd) == -1) || (pid = fork()) == -1)
        ft_putstr("error: fatal\n"), exit(1);
    if (pid == 0)
    {
        av[ac] = 0;
        ft_setpipe(has_pipe, fd, 1);
        if (!strcmp(cmd, "cd"))
            exit(ft_cd(ac, av[1]));
        if (execve(cmd, av, env) == -1)
            ft_putstr("error: cannot execute "), ft_putstr(cmd), ft_putstr("\n"), exit(1);
    }
    waitpid(pid, &status, 0);
    ft_setpipe(has_pipe, fd, 0);
    return(WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char *av[], char *env[])
{
    int status = 0;
    int i = 0;

    (void)ac;
    while (av[i])
    {
        av += i + 1;
        i = 0;
        while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
            i++;
        if (i)
            status = ft_exec(i, av, env, av[i] && !strcmp(av[i], "|"));
    }
    return (status);
}