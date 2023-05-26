/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:50 by pedro             #+#    #+#             */
/*   Updated: 2023/05/26 08:47:32 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct t_path
{
	char			*path;
	char			**path_and_cmd;
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

t_path				*set_path_list(t_path *path_list, char *path,
						char **path_and_cmd);
char				**set_possible_paths(char **envp);
t_path				*find_path(t_path *path_list, char **possible_paths,
						char *av, char **path_and_cmd);
t_path				*absolute_path(t_path *path_list, char *av,
						char **path_and_cmd);
t_path				*define_path(t_path *path_list, int ac, char **av,
						char **envp);
t_path				*add_path(char *path, char **path_and_cmd);
void				print_path_list(t_path **paths_list);
void				add_tail(t_path **list_head, t_path *new_path);
t_path				*find_last(t_path *paths_list);

/* --- Child Process Functions --- */

void				process_1(t_pipe pipex, int fds[], char **envp);
void				process_2(t_pipe pipex, int fds[], char **envp);

/* --- Checker Functions --- */

void				check_ac(int ac);
int					*check_fd(int fd[], char **av, int ac);

/* --- Free Functions --- */

void				free_path_list(t_path **paths_list);
void				free_pipex(t_pipe pipex);
void				free_matrix(char **matrix);

char				*new_strjoin(char const *s1, char const *s2,
						char const *s3);

#endif