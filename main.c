/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/05/23 00:37:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_content(t_pipe *pipex, char **av, char **envp)
{
	pipex->path1 = find_path(envp, av[2]);
	pipex->path2 = find_path(envp, av[3]);
	pipex->cmd1 = av[2];
	pipex->cmd2 = av[3];
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;

	check_ac(ac);
	check_fd(&pipex, av);
	set_content(&pipex, av, envp);
	start_child_process(pipex);
	return (0);
}
