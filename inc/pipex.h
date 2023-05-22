/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:49:50 by pedro             #+#    #+#             */
/*   Updated: 2023/05/22 23:06:02 by pedro            ###   ########.fr       */
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

t_path				*find_path(t_path *path_list, char **envp, char *cmd);
t_path				*find_last(t_path *paths_list);
void				add_tail(t_path **list_head, t_path *new_path);
t_path				*add_path(char *path);
void				free_path(t_path **paths_list);
void				print_path(t_path **paths_list);
t_path				*set_path_list(t_path *path_list, char **paths, char *cmd);
int					try_acess(t_path **path_list);
void				start_child_process(char **av);
void				check_ac(int ac);
char				**handle_path(char **envp);

#endif