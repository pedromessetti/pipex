/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/06/12 15:19:59 by pedro            ###   ########.fr       */
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
	while (1) 
	{
		write(1, "pipex> ", 8);
		buf = get_next_line(STDIN_FILENO);
		if (buf)
		{
			if (ft_strncmp(limiter, buf, ft_strlen(limiter)) == 0 && (ft_strlen(buf) == ft_strlen(limiter)))
				break;
			write(fd, buf, ft_strlen(buf));
			free(buf);
		}
	}
	free(tmp);
	free(limiter);
	free(buf);
}

int	main(int ac, char **av, char **envp)
{
	t_path	*path_list;
	int		fd[2];

	path_list = NULL;
	check_ac(ac);
	check_fd(fd, av, ac);
	if (is_here_doc(av[1]))
		handle_here_doc(av[2], fd[0]);
	path_list = define_path(path_list, ac, av, envp);
	start_process(path_list, fd, envp);
	free_path_list(&path_list);
	unlink(".tmp");
	return (0);
}
