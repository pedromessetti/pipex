/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:24:15 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/27 18:06:16 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_here_doc(int ac, char **av, int fd[])
{
	fd[0] = STDIN_FILENO;
    fd[1] = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
}
