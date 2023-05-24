/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:32 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/24 14:44:08 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_1(t_pipe pipex, int fds[])
{
	close(fds[0]);
	dup2(pipex.fd1, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close(pipex.fd1);
	close(pipex.fd2);
	close(fds[1]);
	execv(pipex.path1, pipex.cmd1);
	ft_printf("pipex: Error executing the command");
	exit(1);
}

void	process_2(t_pipe pipex, int fds[])
{
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	dup2(pipex.fd2, STDOUT_FILENO);
	close(pipex.fd1);
	close(pipex.fd2);
	close(fds[0]);
	execv(pipex.path2, pipex.cmd2);
	ft_printf("pipex: Error executing the command");
	exit(1);
}
