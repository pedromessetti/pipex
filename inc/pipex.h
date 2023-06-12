/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:50 by pedro             #+#    #+#             */
/*   Updated: 2023/06/12 10:10:44 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
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
	pid_t			pid;
	int				pipe_fd[2];
	struct t_path	*next;
	struct t_path	*prev;
}					t_path;

/* --- Path Functions --- */

char				**set_possible_paths(char **envp);
t_path				*find_path(t_path *path_list, char **possible_paths,
						char *av, char **path_and_cmd);
t_path				*absolute_path(t_path *path_list, char *av,
						char **path_and_cmd);
t_path				*define_path(t_path *path_list, int ac, char **av,
						char **envp);

/* --- List Functions --- */

t_path				*add_path(char *path, char **path_and_cmd);
void				add_tail(t_path **list_head, t_path *new_path);
t_path				*find_last(t_path *paths_list);
void				free_path_list(t_path **paths_list);
t_path				*set_path_list(t_path *path_list, char *path,
						char **path_and_cmd);

/* --- Child Process Functions --- */

void				child_process(t_path *path_list, char **envp);
void				bind_stds(t_path *curr, int fd[]);
void				start_process(t_path *path_list, int fd[], char **envp);

/* --- Checker Functions --- */

void				check_ac(int ac);
int					*check_fd(int fd[], char **av, int ac);
int					check_builtin(char *av);
void				check_exit_status(t_path *path_list);
int					is_here_doc(char *s);

/* --- Utils Functions --- */

void				free_matrix(char **matrix);
char				*new_strjoin(char const *s1, char const *s2,
						char const *s3);
int					str_is_num(char *s);
#endif