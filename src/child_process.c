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
		close(pipe_fds[0]);               // Close unused read end of the pipe
		dup2(pipex.fd1, STDIN_FILENO);    // Redirect stdin to pipex.fd1
		dup2(pipe_fds[1], STDOUT_FILENO); // Redirect stdout to pipe
		close(pipex.fd1);
		close(pipex.fd2);
		close(pipe_fds[1]);
		execv(pipex.path1, pipex.cmd1);
		ft_printf("pipex: Error executing the command");
		exit(1);
	}
	else
	{
		// Parent process
		close(pipe_fds[1]); // Close unused write end of the pipe
		// Read from the pipe and write to file2_fd
		while ((bytesRead = read(pipe_fds[0], buffer, sizeof(buffer))) > 0)
		{
			write(pipex.fd2, buffer, bytesRead);
		}
		close(pipex.fd1);
		close(pipex.fd2);
		close(pipe_fds[0]);
		// Wait for the child process to finish
		wait(NULL);
	}
}
