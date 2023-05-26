/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:36 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/26 14:25:23 by pmessett         ###   ########.fr       */
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

int	*check_fd(int fd[], char **av, int ac)
{
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
	{
		ft_printf("pipex: %s: Archive not found\n", av[1]);
		exit(EXIT_FAILURE);
	}
	fd[1] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[1] == -1)
	{
		ft_printf("pipex: Error opening/creating the file\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
