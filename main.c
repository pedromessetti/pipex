/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:42 by pedro             #+#    #+#             */
/*   Updated: 2023/05/21 10:24:32 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	pid;
	int n;
	int	file1_fd;

	if (ac > 4)
	{
		pid = fork();
		if (pid == 0)
		{
			n = 1;
		}
		else
		{
			n = 6;
		}

		for (int i = n; i < n + 5; i++)
			printf("%d ", i);
		
		file1_fd = open(av[1], O_RDONLY);
		//int file2_fd = open(av[4], O_RDONLY);
		if (file1_fd < 0)
			printf("%s: Archive not found\n", av[1]);
		printf("%s\n", envp[1]);
	}
	else
		exit(1);
	return (0);
}
