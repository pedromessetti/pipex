/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:05:06 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/24 19:23:39 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp, char *cmd)
{
	char	**paths;
	int		i;
	t_path	*path_list;
	char	*result;
	char	*tmp;

	if (!cmd)
		return (NULL);
	path_list = NULL;
	i = -1;
	paths = handle_path_aux(envp);
	path_list = handle_path(path_list, paths, cmd);
	if (try_acess(&path_list))
	{
		result = ft_strdup(path_list->path);
		free_path_list(&path_list);
		return (result);
	}
	else
	{
		ft_printf("pipex: %s: command not found\n", cmd);
		free_path_list(&path_list);
		return (NULL);
	}
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
		free((*path_list)->path);
		(*path_list)->path = NULL;
		free(*path_list);
		(*path_list) = tmp;
	}
	return (0);
}

char	**handle_path_aux(char **envp)
{
	char	*path;
	char	**paths;
	int		i;
	char	*tmp;

	i = -1;
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

t_path	*handle_path(t_path *path_list, char **paths, char *cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		add_path(&path_list, ft_strjoin(tmp, cmd));
		free(tmp);
		free(paths[i]);
	}
	free(paths);
	return (path_list);
}
