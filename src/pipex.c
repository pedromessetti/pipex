/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:05:06 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/23 15:07:15 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp, char *cmd)
{
	char	**paths;
	int		i;
	t_path	*path_list;

	path_list = NULL;
	i = -1;
	while (cmd[++i] != ' ' && cmd[i])
		;
	cmd[i] = '\0';
	paths = handle_path(envp);
	path_list = set_path_list(path_list, paths, cmd);
	print_path(&path_list);
	free(paths);
	if (try_acess(&path_list))
		return (path_list->path);
	else
	{
		ft_printf("pipex: %s: command not found\n", cmd);
		free_path(&path_list);
		exit(1);
	}
}

t_path	*set_path_list(t_path *path_list, char **paths, char *cmd)
{
	int	i;

	i = -1;
	while (paths[++i])
	{
		if (!path_list)
			path_list = add_path(ft_strjoin(ft_strjoin(paths[i], "/"), cmd));
		else
			add_tail(&path_list, add_path(ft_strjoin(ft_strjoin(paths[i], "/"),
							cmd)));
	}
	return (path_list);
}

int	try_acess(t_path **path_list)
{
	t_path	*tmp;

	if (!path_list)
		return (0);
	while (*path_list)
	{
		tmp = (*path_list)->next;
		if (!access((*path_list)->path, F_OK))
			return (1);
		(*path_list)->path = 0;
		free(*path_list);
		(*path_list) = tmp;
	}
	return (0);
}

char	**handle_path(char **envp)
{
	char *path;
	char **paths;
	int i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i];
			break ;
		}
	}
	path = ft_substr(path, 5, ft_strlen(path));
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}