/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:50 by pedro             #+#    #+#             */
/*   Updated: 2023/05/24 19:23:48 by pmessett         ###   ########.fr       */
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
	char			**cmd1;
	char			**cmd2;
	int				fd1;
	int				fd2;
}					t_pipe;

/* --- Path Functions --- */

char				*find_path(char **envp, char *cmd);
void				add_path(t_path **path_list, char *path);
t_path				*handle_path(t_path *path_list, char **paths, char *cmd);
char				**handle_path_aux(char **envp);
int					try_acess(t_path **path_list);
void				print_path_list(t_path **paths_list);

/* --- Child Process Functions --- */

void				process_1(t_pipe pipex, int fds[], char **envp);
void				process_2(t_pipe pipex, int fds[], char **envp);

/* --- Checker Functions --- */

void				check_ac(int ac);
void				check_fd(t_pipe *pipex, char **av);

/* --- Free Functions --- */

void				free_path_list(t_path **paths_list);
void				free_pipex(t_pipe pipex);
void				free_matrix(char **matrix);

#endif