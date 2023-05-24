#include "pipex.h"

//Removeble function
void	print_path(t_path **paths_list)
{
	t_path	*curr;

	curr = *paths_list;
	while (curr)
	{
		ft_printf("Path => %s\n", curr->path);
		curr = curr->next;
	}
}

/* Free the allocated memory for the cost paths_list */
void	free_path(t_path **paths_list)
{
	t_path	*tmp;

	if (!paths_list)
		return ;
	while (*paths_list)
	{
		tmp = (*paths_list)->next;
		(*paths_list)->path = 0;
		free(*paths_list);
		(*paths_list) = tmp;
	}
}

/*Add a new node at the beginning of the cost paths_list*/
t_path	*add_path(char *path)
{
	t_path	*new_path;

	new_path = (t_path *)malloc(sizeof(t_path));
	if (!new_path)
		return (NULL);
	new_path->path = path;
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
