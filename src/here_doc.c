/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:33:45 by pedro             #+#    #+#             */
/*   Updated: 2023/06/15 17:57:35 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_here_doc(char *s)
{
	if (((ft_strncmp(s, "here_doc\0", ft_strlen("here_doc") + 1)) == 0))
		return (1);
	return (0);
}

int	is_limiter(char *limiter, char *buf)
{
	if (ft_strncmp(limiter, buf, ft_strlen(limiter)) == 0
		&& (ft_strlen(buf) == ft_strlen(limiter)))
		return (1);
	return (0);
}

void	handle_here_doc(char *av, int fd[], t_path *path_list)
{
	char	*buf;
	char	*tmp;
	char	*limiter;
	int		heredoc_pipe[2];

	pipe(heredoc_pipe);
	fd[0] = heredoc_pipe[0];
	tmp = ft_strdup(av);
	limiter = ft_strjoin(tmp, "\n");
	while (1)
	{
		write(1, "pipex> ", 7);
		buf = get_next_line(STDIN_FILENO);
		if (buf)
		{
			if (is_limiter(limiter, buf))
				break ;
			write(heredoc_pipe[1], buf, ft_strlen(buf));
			free(buf);
		}
	}
	close(heredoc_pipe[1]);
	free(tmp);
	free(limiter);
	free(buf);
}
