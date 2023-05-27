/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:32 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/27 19:27:22 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_path *path_list, char **envp)
{
	execve(path_list->path, path_list->path_and_cmd, envp);
	free_path_list(&path_list);
	exit(EXIT_FAILURE);
}

void	bind_stds(t_path *curr, int fds[])
{
	if (!curr->prev)
	{
		if (dup2(fds[0], STDIN_FILENO) != -1)
			close(fds[0]);
	}
	else
	{
		if (dup2(curr->prev->pipe_fds[0], STDIN_FILENO) != -1)
			close(curr->prev->pipe_fds[0]);
	}
	if (!curr->next)
	{
		if (dup2(fds[1], STDOUT_FILENO) != -1)
			close(fds[1]);
	}
	else
	{
		if (dup2(curr->pipe_fds[1], STDOUT_FILENO) != -1)
			close(curr->pipe_fds[1]);
	}
	close(fds[0]);
	close(fds[1]);
	close(curr->pipe_fds[0]);
	close(curr->pipe_fds[1]);
}

void	start_process(t_path *path_list, int fds[], char **envp)
{
	pid_t	process_id;
	t_path	*curr;

	curr = path_list;
	while (curr)
	{
		if (pipe(curr->pipe_fds) == -1)
			return ;
		process_id = fork();
		curr->pid = process_id;
		if (process_id == 0)
		{
			bind_stds(curr, fds);
			child_process(curr, envp);
			return ;
		}
		else if (process_id == -1)
		{
			ft_printf("pipex: Error during fork process\n");
			free_path_list(&path_list);
			exit(EXIT_FAILURE);
		}
		if (!curr->prev)
			close(fds[0]);
		else
			close(curr->prev->pipe_fds[0]);
		if (!curr->next)
		{
			close(fds[1]);
			close(curr->pipe_fds[0]);
		}
		close(curr->pipe_fds[1]);
		curr = curr->next;
	}
	curr = path_list;
	while (curr)
	{
		waitpid(curr->pid, NULL, 0);
		curr = curr->next;
	}
}
