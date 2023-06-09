/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:36 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/18 14:35:15 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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

int	is_dir(char *s)
{
	if ((ft_strncmp(s, "/", 1)) == 0 || (ft_strncmp(s, "./", 2)) == 0)
		return (1);
	return (0);
}

int	*check_fd(int fd[], char **av, int ac)
{
	int	flags;

	flags = O_CREAT | O_WRONLY | O_TRUNC;
	if (is_here_doc(av[1]))
		flags = O_CREAT | O_WRONLY | O_APPEND;
	fd[1] = open(av[ac - 1], flags, 0644);
	if (fd[1] == -1)
	{
		ft_printf("pipex: Error opening/creating the file\n");
		exit(EXIT_FAILURE);
	}
	if (!is_here_doc(av[1]))
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] == -1)
		{
			perror(av[1]);
			exit(EXIT_FAILURE);
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
	if (ft_str_is_num(path_list->path_and_cmd[1])
		|| !path_list->path_and_cmd[1])
		return ;
	else
		ft_printf("exit: %s: numeric argument required\n",
			path_list->path_and_cmd[1]);
}
