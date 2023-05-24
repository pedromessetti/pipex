#include "pipex.h"

void	process_1(t_pipe pipex, int fds[])
{
	close(fds[0]);
	dup2(pipex.fd1, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close(pipex.fd1);
	close(pipex.fd2);
	close(fds[1]);
	char	*command[] = {pipex.path1, pipex.cmd1, NULL};
	execv(pipex.path1, command);
	ft_printf("pipex: Error executing the command");
	exit(1);
}

void process_2(t_pipe pipex, int fds[])
{
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	dup2(pipex.fd2, STDOUT_FILENO);
	close(pipex.fd1);
	close(pipex.fd2);
	close(fds[0]);
	char	*command[] = {pipex.path2, pipex.cmd2, NULL};
	execv(pipex.path2, command);
	ft_printf("pipex: Error executing the command");
	exit(1);
}
