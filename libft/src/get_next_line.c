/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:41:58 by pedro             #+#    #+#             */
/*   Updated: 2023/06/09 22:57:00 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function clears the buffer and moves 
any remaining characters after a newline ('\\n') 
to the beginning of the buffer. Also keeps 
track of a newline was found or not. 
Return 1 if a newline was found
Return 0 otherwise*/
int	ft_buffer_clear(char *s)
{
	int	i;
	int	j;
	int	is_new_line;

	i = 0;
	j = 0;
	is_new_line = 0;
	while (s[i])
	{
		if (is_new_line)
			s[j++] = s[i];
		if (s[i] == '\n')
			is_new_line = 1;
		s[i++] = '\0';
	}

	return (is_new_line);
}

/* Reads a line from a file descriptor.
Return a string. */
char	*get_next_line(int fd)
{
	/* Static buffer to store characters read from the file */
	static char	buf[BUFFER_SIZE + 1];
	/* Pointer to the line being read */
	char		*line;
	/* Number of bytes read from the file */
	int			read_bytes;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);

	line = ft_strjoin(0, buf);
	
	/* If a newline was found in the buffer, return the line without reading from the file further. */
	if (ft_buffer_clear(buf))
		return (line);

	/* Read from the file descriptor into the buffer. */
	read_bytes = read(fd, buf, BUFFER_SIZE);

	/* If an error occurred during the read operation, free the line and return NULL. */
	if (read_bytes < 0)
	{
		free(line);
		return (NULL);
	}

	/* Read from the file until a newline or the end of the file. */
	while (read_bytes)
	{
		line = ft_strjoin(line, buf); // Join the contents of the buffer with the line
		/* If a newline was found in the buffer, break out of the loop */
		if (ft_buffer_clear(buf))
			break ;
		read_bytes = read(fd, buf, BUFFER_SIZE); // Read from the file descriptor into the buffer
	}

	return (line);
}
