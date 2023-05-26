/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:43:27 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/26 08:47:24 by pedro            ###   ########.fr       */
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
		printf("path => %s\n", curr->path);
		printf("path_and_cmd[0] => %s\n", curr->path_and_cmd[0]);
		printf("path_and_cmd[1] => %s\n", curr->path_and_cmd[1]);
		curr = curr->next;
	}
}

/* Free the allocated memory for the paths_list */
void	free_path_list(t_path **paths_list)
{
	t_path	*tmp;

	tmp = NULL;
	if (!paths_list)
		return ;
	while (*paths_list)
	{
		tmp = (*paths_list)->next;
		free_matrix((*paths_list)->path_and_cmd);
		if (!(*paths_list)->path)
			free((*paths_list)->path);
		free(*paths_list);
		*paths_list = tmp;
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
	return (new_path);
}

/*Add a new node at the end of the cost paths_list*/
void	add_tail(t_path **list_head, t_path *new_path)
{
	if (!list_head)
		return ;
	if (!*list_head)
		*list_head = new_path;
	else
		(find_last(*list_head))->next = new_path;
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

 char	*new_strjoin(char const *s1, char const *s2, char const *s3)
{
	char	*new_s;
	size_t	i;
	size_t	j;
	size_t	k;

	new_s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	if (!new_s)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_s[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_s[i++] = s2[j];
	k = -1;
	while (s3[++k])
		new_s[i++] = s3[k];
	new_s[i] = '\0';
	return (new_s);
}
