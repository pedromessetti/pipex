/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:32 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/05 07:44:39 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_path *path_list, char **envp)
{
	char	*tmp;

	if (tmp = ft_strnstr(path_list->path, "/exit\0", ft_strlen(path_list->path)))
		if (check_builtin(++tmp))
			check_exit_status(path_list);
	execve(path_list->path, path_list->path_and_cmd, envp);
	free_path_list(&path_list);
	exit(EXIT_SUCCESS);
}

void	bind_stds(t_path *curr, int fd[])
{
	if (!curr->prev)
	{
		if (dup2(fd[0], STDIN_FILENO) != -1)
			close(fd[0]);
	}
	else
	{
		if (dup2(curr->prev->pipe_fd[0], STDIN_FILENO) != -1)
			close(curr->prev->pipe_fd[0]);
	}
	if (!curr->next)
	{
		if (dup2(fd[1], STDOUT_FILENO) != -1)
			close(fd[1]);
	}
	else
	{
		if (dup2(curr->pipe_fd[1], STDOUT_FILENO) != -1)
			close(curr->pipe_fd[1]);
	}
	close(fd[0]);
	close(fd[1]);
	close(curr->pipe_fd[0]);
	close(curr->pipe_fd[1]);
}

void	start_process(t_path *path_list, int fd[], char **envp)
{
	pid_t	process_id;
	t_path	*curr;

	curr = path_list;
	while (curr)
	{
		if (pipe(curr->pipe_fd) == -1)
			return ;
		process_id = fork();
		curr->pid = process_id;
		if (process_id == 0)
		{
			bind_stds(curr, fd);
			child_process(curr, envp);
			return ;
		}
		else if (process_id == -1)
		{
			ft_printf("Error during fork process\n");
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
		waitpid(curr->pid, NULL, 0);
		curr = curr->next;
	}
}
