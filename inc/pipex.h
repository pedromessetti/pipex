/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:50 by pedro             #+#    #+#             */
/*   Updated: 2023/05/24 10:52:46 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct t_path
{
	char			*path;
	struct t_path	*next;
}					t_path;

typedef struct t_pipe
{
	char			*path1;
	char			*path2;
	char			*cmd1;
	char			*cmd2;
	int				fd1;
	int				fd2;
}					t_pipe;

char				*find_path(char **envp, char *cmd);
t_path				*find_last(t_path *paths_list);
void				add_tail(t_path **list_head, t_path *new_path);
void				add_path(t_path **path_list, char *path);
void				free_path(t_path **paths_list);
void				print_path(t_path **paths_list);
int					try_acess(t_path **path_list);
void				process_1(t_pipe pipex, int fds[]);
void				process_2(t_pipe pipex, int fds[]);
void				check_ac(int ac);
void				check_fd(t_pipe *pipex, char **av);
char				**handle_path(char **envp);

#endif