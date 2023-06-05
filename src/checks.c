/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:36 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/05 07:46:34 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_ac(int ac)
{
	if (ac >= 5)
		return ;
	if (ac < 5)
	{
		ft_printf("pipex: too few arguments\n");
		exit(EXIT_FAILURE);
	}
}

static int	check_is_dir(char *s)
{
	if (!(ft_strncmp(s, "/", 1)) || !(ft_strncmp(s, "./", 2)))
		if (access(s, F_OK) != -1)
			return (1);
	return (0);
}

int	*check_fd(int fd[], char **av, int ac)
{
	fd[1] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[1] == -1)
	{
		ft_printf("Error opening/creating the file\n");
		exit(EXIT_FAILURE);
	}
	if (((ft_strncmp(av[1], "here_doc\0", ft_strlen("here_doc") + 1)) == 0))
		fd[0] = STDIN_FILENO;
	else
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] == -1)
		{
			fd[0] = open(".tmp", O_CREAT | O_RDONLY, 0444);
			if (check_is_dir(av[1]) && fd[0] == -1)
				ft_printf("pipex: (standard input) is a directory\n");
			else
				perror(av[1]);
		}
	}
	return (fd);
}

int	check_builtin(char *av)
{
	if (ft_strncmp(av, "exit\0", ft_strlen("exit") + 1) == 0 || ft_strncmp(av,
			"exit ", ft_strlen("exit ")) == 0)
		return (1);
	if (ft_strncmp(av, "cd\0", ft_strlen("cd") + 1) == 0 || ft_strncmp(av,
			"cd ", ft_strlen("cd ")) == 0)
		return (1);
	return (0);
}

void	check_exit_status(t_path *path_list)
{
	if (str_is_num(path_list->path_and_cmd[1]) || !path_list->path_and_cmd[1])
		return ;
	else
		ft_printf("exit: %s: numeric argument required\n",
			path_list->path_and_cmd[1]);
}