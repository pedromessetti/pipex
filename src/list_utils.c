/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:27 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/17 15:51:45 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*Checks if the path_list is empity, if it is, add a new path to the top,
else add a new path in the end*/
t_path	*set_path_list(t_path *path_list, char *path, char **path_and_cmd)
{
	t_path	*new_list;

	new_list = NULL;
	if (!path_list)
		path_list = add_path(path, path_and_cmd);
	else
	{
		new_list = add_path(path, path_and_cmd);
		add_tail(&path_list, new_list);
	}
	return (path_list);
}

/*Free the allocated memory for the paths_list*/
void	free_path_list(t_path **path_list)
{
	t_path	*tmp;

	tmp = NULL;
	if (!*path_list)
		return ;
	while ((*path_list)->prev)
		*path_list = (*path_list)->prev;
	while (*path_list)
	{
		tmp = (*path_list)->next;
		if ((*path_list)->path_and_cmd)
			free_matrix((*path_list)->path_and_cmd);
		if (!(*path_list)->path)
			free((*path_list)->path);
		free(*path_list);
		*path_list = tmp;
	}
}

/*Add a new node at the beginning of the paths_list*/
t_path	*add_path(char *path, char **path_and_cmd)
{
	t_path	*new_path;

	new_path = (t_path *)malloc(sizeof(t_path));
	if (!new_path)
		return (NULL);
	new_path->path = path;
	new_path->path_and_cmd = path_and_cmd;
	new_path->next = NULL;
	new_path->prev = NULL;
	return (new_path);
}

/*Add a new node at the end of the cost paths_list*/
void	add_tail(t_path **list_head, t_path *new_path)
{
	t_path	*last;

	last = find_last(*list_head);
	if (!list_head)
		return ;
	if (!*list_head)
		*list_head = new_path;
	else
	{
		last->next = new_path;
		new_path->prev = last;
	}
}

/*Iterates into the cost paths_list and returns the last node*/
t_path	*find_last(t_path *paths_list)
{
	if (!paths_list)
		return (NULL);
	while (paths_list->next)
		paths_list = paths_list->next;
	return (paths_list);
}
