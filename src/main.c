/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/05/26 14:20:52 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_here_doc(void)
{
	printf("Handling here-document..\n");
	exit(EXIT_SUCCESS);
}

static void	print_path_list(t_path **paths_list)
{
	t_path	*curr;

	curr = *paths_list;
	while (curr)
	{
		printf("path => %s\n", curr->path);
		printf("path_and_cmd[0] => %s\n", curr->path_and_cmd[0]);
		printf("path_and_cmd[1] => %s\n", curr->path_and_cmd[1]);
		curr = curr->next;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_path	*path_list;
	int		fds[2];

	path_list = NULL;
	check_ac(ac);
	if (!(ft_strncmp(av[1], "here_doc", ft_strlen(av[1]))))
		handle_here_doc();
	check_fd(fds, av, ac);
	path_list = define_path(path_list, ac, av, envp);
	start_process(path_list, fds, envp);
	free_path_list(&path_list);
	return (0);
}
