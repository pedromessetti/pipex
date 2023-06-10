/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/06/09 23:41:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_path_list(t_path **paths_list)
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
}

static void handle_here_doc(char *av, int fd)
{
	char *buf;
	char *tmp = ft_strdup(av);
	char *limiter = ft_strjoin(tmp, "\n");
	free(tmp);
	while (1) {
		write(1, ">", 1);
		buf = get_next_line(0);
		if (buf)
		{
			if(ft_strlen(buf) == ft_strlen(tmp))
				if(ft_strncmp(tmp, buf, ft_strlen(limiter)) == 0)
					break;
			write(fd, buf, ft_strlen(buf));
			free(buf);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_path	*path_list;
	int		fd[2];

	path_list = NULL;
	check_ac(ac);
	check_fd(fd, av, ac);
	if (((ft_strncmp(av[1], "here_doc\0", ft_strlen("here_doc") + 1)) == 0))
		handle_here_doc(av[2], fd[0]);
	path_list = define_path(path_list, ac, av, envp);
	start_process(path_list, fd, envp);
	//print_path_list(&path_list);
	free_path_list(&path_list);
	unlink(".tmp");
	return (0);
}
