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

/* Free the allocated memory for the paths_list */
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
