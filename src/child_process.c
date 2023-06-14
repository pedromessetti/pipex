/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:32 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/14 14:50:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_path *path_list, char **envp)
{
	char	*tmp;

	if (tmp = ft_strnstr(path_list->path, "/exit\0",
			ft_strlen(path_list->path)))
		if (check_builtin(++tmp))
			check_exit_status(path_list);
	if (path_list->path)
		execve(path_list->path, path_list->path_and_cmd, envp);
	close(path_list->dup2_fd[0]);
	close(path_list->dup2_fd[1]);
	free_path_list(&path_list);
	exit(EXIT_FAILURE);
}

void	bind_stds(t_path *curr, int fd[])
{
	if (!curr->prev)
	{
		curr->dup2_fd[0] = dup2(fd[0], STDIN_FILENO);
		if (curr->dup2_fd[0] != -1)
			close(fd[0]);
	}
	else
	{
		curr->dup2_fd[0] = dup2(curr->prev->pipe_fd[0], STDIN_FILENO);
		if (curr->dup2_fd[0] != -1)
			close(curr->prev->pipe_fd[0]);
	}
	if (!curr->next)
	{
		curr->dup2_fd[1] = dup2(fd[1], STDOUT_FILENO);
		if (curr->dup2_fd[1] != -1)
			close(fd[1]);
	}
	else
	{
		curr->dup2_fd[1] = dup2(curr->pipe_fd[1], STDOUT_FILENO);
		if (curr->dup2_fd[1] != -1)
			close(curr->pipe_fd[1]);
	}
	close(fd[0]);
	close(fd[1]);
	close(curr->pipe_fd[0]);
	close(curr->pipe_fd[1]);
}

int	start_process(t_path *path_list, int fd[], char **envp, char **av)
{
	pid_t	process_id;
	t_path	*curr;
	int		exit_status;

	exit_status = 0;
	curr = path_list;
	while (curr)
	{
		if (pipe(curr->pipe_fd) == -1)
			return 1;
		if (is_here_doc(av[1]) && !curr->prev)
			handle_here_doc(av[2], fd, curr);
		process_id = fork();
		curr->pid = process_id;
		if (process_id == 0)
		{
			bind_stds(curr, fd);
			child_process(curr, envp);
			return (1);
		}
		else if (process_id == -1)
		{
			ft_printf("pipex: Error during fork process\n");
			free_path_list(&path_list);
			exit(EXIT_FAILURE);
		}
		if (!curr->prev)
			close(fd[0]);
		else
			close(curr->prev->pipe_fd[0]);
		if (!curr->next)
		{
			close(fd[1]);
			close(curr->pipe_fd[0]);
		}
		close(curr->pipe_fd[1]);
		curr = curr->next;
	}
	curr = path_list;
	while (curr)
	{
		waitpid(curr->pid, &exit_status, 0);
		if (WIFEXITED(exit_status))
			exit_status = WEXITSTATUS(exit_status);
		curr = curr->next;
	}
	return (exit_status);
}
