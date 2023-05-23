/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/05/23 10:47:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_content(t_pipe *pipex, char **av, char **envp)
{
	pipex->cmd1 = set_command(av[2]);
	pipex->path1 = find_path(envp, av[2]);
	pipex->path2 = find_path(envp, av[3]);
	pipex->cmd2 = set_command(av[3]);
}

char	*set_command(char *av)
{
	char	*cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (av[i] && av[i] != ' ')
		i++;
	if (!av[i])
		return (NULL);
	else
	{
		while (av[++i])
			cmd[j++] = av[i];
	}
	cmd[j] = '\0';
	return (cmd);
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
