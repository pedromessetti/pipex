/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:36 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/24 18:33:08 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_ac(int ac)
{
	if (ac == 5)
		return ;
	else if (ac < 5)
	{
		ft_printf("pipex: too few arguments\n");
		exit(1);
	}
	else if (ac > 5)
	{
		ft_printf("pipex: too many arguments\n");
		exit(1);
	}
}

void	check_fd(t_pipe *pipex, char **av)
{
	pipex->fd1 = open(av[1], O_RDONLY);
	if (pipex->fd1 == -1)
	{
		ft_printf("pipex: %s: Archive not found\n", av[1]);
		exit(1);
	}
	pipex->fd2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->fd2 == -1)
	{
		ft_printf("pipex: Error opening/creating the file");
		exit(1);
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}
