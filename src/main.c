/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/05/26 11:13:21 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_here_doc(void)
{
	printf("Handling here-document..\n");
	exit(EXIT_SUCCESS);
}

static void	child_process(t_path *path_list, int pipe_fds[], int fds[],
		char **envp)
{
	//printf("PATH => %s\n", path_list->path);
	close(pipe_fds[0]);
	dup2(fds[0], STDIN_FILENO);
	dup2(pipe_fds[1], STDOUT_FILENO);
	execve(path_list->path, path_list->path_and_cmd, envp);
	return ;
}

static void	last_process(t_path *path_list, int pipe_fds[], int fds[],
		char **envp)
{
	//printf("PATH => %s\n", path_list->path);
	close(pipe_fds[1]);
	dup2(pipe_fds[0], STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	execve(path_list->path, path_list->path_and_cmd, envp);
	free_path_list(&path_list);
	exit(1);
}

static void	start_process(t_path *path_list, int pipe_fds[], int fds[],
		char **envp)
{
	pid_t	process_id;
	t_path	*curr;

	curr = path_list;
	while (curr)
	{
		process_id = fork();
		if (process_id == 0)
		{
			if (curr->next)
				child_process(curr, pipe_fds, fds, envp);
			else
				last_process(curr, pipe_fds, fds, envp);
			return ;
		}
		else if (process_id > 0)
		{
			if (!curr->next)
				return ;
		}
		else
		{
			ft_printf("pipex: Error during fork process\n");
			exit(EXIT_FAILURE);
		}
		waitpid(process_id, NULL, 0);
		curr = curr->next;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_path	*path_list;
	int		fds[2];
	int		pipe_fds[2];

	path_list = NULL;
	check_ac(ac);
	if (!(ft_strncmp(av[1], "here_doc", ft_strlen(av[1]))))
		handle_here_doc();
	check_fd(fds, av, ac);
	if (pipe(pipe_fds) == -1)
		exit(EXIT_FAILURE);
	path_list = define_path(path_list, ac, av, envp);
	start_process(path_list, pipe_fds, fds, envp);
	//print_path_list(&path_list);
	free_path_list(&path_list);
	return (0);
}
