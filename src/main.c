/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/05/24 14:43:15 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_content(t_pipe *pipex, char **av, char **envp)
{
	char	**cmd1;
	char	**cmd2;

	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');
	pipex->cmd1 = cmd1;
	pipex->path1 = find_path(envp, cmd1[0]);
	pipex->cmd2 = cmd2;
	pipex->path2 = find_path(envp, cmd2[0]);
}

void	free_pipex(t_pipe pipex)
{
	free_matrix(pipex.cmd1);
	free_matrix(pipex.cmd2);
	free(pipex.path1);
	free(pipex.path2);
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;
	int		fds[2];
	pid_t	child_process_1;
	pid_t	child_process_2;

	check_ac(ac);
	check_fd(&pipex, av);
	set_content(&pipex, av, envp);
	if (pipe(fds) == -1)
	{
		ft_printf("pipex: Error creating pipe");
		exit(1);
	}
	child_process_1 = fork();
	if (child_process_1 == 0)
		process_1(pipex, fds);
	child_process_2 = fork();
	if (child_process_2 == 0)
		process_2(pipex, fds);
	wait(NULL);
	free_pipex(pipex);
	return (0);
}
