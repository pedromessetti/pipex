/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:27 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/24 14:51:15 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Removeble function
void	print_path_list(t_path **paths_list)
{
	t_path	*curr;

	curr = *paths_list;
	while (curr)
	{
		ft_printf("Path => %s\n", curr->path);
		curr = curr->next;
	}
}

/* Free the allocated memory for the paths_list */
void	free_path_list(t_path **paths_list)
{
	t_path	*tmp;

	if (!paths_list)
		return ;
	while (*paths_list)
	{
		tmp = (*paths_list)->next;
		free((*paths_list)->path);
		(*paths_list)->path = NULL;
		free(*paths_list);
		(*paths_list) = tmp;
	}
}

/*Add a new node at the beginning of the paths_list*/
void	add_path(t_path **path_list, char *path)
{
	t_path	*new_path;

	new_path = (t_path *)malloc(sizeof(t_path));
	if (!new_path)
		return ;
	new_path->path = path;
	new_path->next = (*path_list);
	*path_list = new_path;
}
