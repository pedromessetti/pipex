/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:32 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/25 08:57:31 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_1(t_pipe pipex, int pipe_fds[], char **envp)
{
	close(pipe_fds[0]);
	dup2(pipex.fd1, STDIN_FILENO);
	dup2(pipe_fds[1], STDOUT_FILENO);
	close(pipex.fd1);
	close(pipex.fd2);
	close(pipe_fds[1]);
	execve(pipex.path1, pipex.cmd1, envp);
	free_pipex(pipex);
	exit(1);
}

void	process_2(t_pipe pipex, int pipe_fds[], char **envp)
{
	close(pipe_fds[1]);
	dup2(pipe_fds[0], STDIN_FILENO);
	dup2(pipex.fd2, STDOUT_FILENO);
	close(pipex.fd1);
	close(pipex.fd2);
	close(pipe_fds[0]);
	execve(pipex.path2, pipex.cmd2, envp);
	free_pipex(pipex);
	exit(1);
}
