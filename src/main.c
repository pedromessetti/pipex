/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/06/18 15:49:40 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
	return (exit_status);
}
