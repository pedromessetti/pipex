#include "pipex.h"

void	start_child_process(t_pipe pipex)
{
	int		pid;
	int		pipe_fds[2];
	char	buffer[256];
	ssize_t	bytesRead;

	if (pipe(pipe_fds) == -1)
	{
		ft_printf("pipex: Error creating pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_printf("pipex: Error forking process\n");
		exit(1);
	}
	if (pid == 0)
	{
		close(pipe_fds[0]);
		dup2(pipex.fd1, STDIN_FILENO);
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipex.fd1);
		close(pipex.fd2);
		close(pipe_fds[1]);
		char *command[] = {pipex.path1, pipex.cmd1, NULL};
		execv(pipex.path1, command);
		ft_printf("pipex: Error executing the command");
		exit(1);
	}
	else
	{
		// Parent process
		close(pipe_fds[1]);
		// Read from the pipe and write to file2_fd
		while ((bytesRead = read(pipe_fds[0], buffer, sizeof(buffer))) > 0)
			write(pipex.fd2, buffer, bytesRead);
		close(pipex.fd1);
		close(pipex.fd2);
		close(pipe_fds[0]);
		// Wait for the child process to finish
		wait(NULL);
	}
}
