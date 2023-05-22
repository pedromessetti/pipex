/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/05/22 22:47:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	pid;
	t_path *path_list;

	path_list = NULL;
	check_ac(ac);
	
	path_list = find_path(path_list, envp, av[2]);
	ft_printf("%s\n",path_list->path);
	free_path(&path_list);

	pid = fork();
	if (pid == -1)
	{
		perror("pipex: process error");
		exit(1);
	}
	if (pid == 0)
		start_child_process(av);
	else
	{
		//parent process
		wait(NULL);
	}
	return (0);
}
