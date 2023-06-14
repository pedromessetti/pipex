/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/06/14 15:09:07 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*static void	print_path_list(t_path **paths_list)
{
	t_path	*curr;

	curr = *paths_list;
	while (curr)
	{
		printf("path => %s\n", curr->path);
		for (int i = 0; curr->path_and_cmd[i]; i++)
			printf("path_and_cmd[%d] => %s\n", i, curr->path_and_cmd[i]);
		curr = curr->next;
	}
}*/

int	main(int ac, char **av, char **envp)
{
	t_path	*path_list;
	int		fd[2];
	int		exit_status;

	path_list = NULL;
	check_ac(ac);
	check_fd(fd, av, ac);
	path_list = define_path(path_list, ac, av, envp);
	exit_status = start_process(path_list, fd, envp, av);
	free_path_list(&path_list);
	unlink(".tmp");
	return (exit_status);
}
