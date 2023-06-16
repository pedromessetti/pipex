/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:16:46 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/16 17:49:15 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

/*Set and returns a array of possible paths by iterate into envp untill
find the PATH variable and split the result by the ':'*/
char	**set_possible_paths(char **envp)
{
	char	*path;
	char	**paths_arr;
	int		i;

	path = NULL;
	paths_arr = NULL;
	i = -1;
	while (envp[++i])
	{
		if (!(ft_strncmp(envp[i], "PATH=", 5)))
		{
			path = envp[i];
			break ;
		}
	}
	path = ft_substr(path, 5, ft_strlen(path));
	paths_arr = ft_split(path, ':');
	free(path);
	return (paths_arr);
}

/*Find the correct path by tryng to acess all the possible paths*/
t_path	*find_path(t_path *path_list, char **possible_paths, char *av,
		char **path_and_cmd)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = -1;
	while (possible_paths[++i])
	{
		tmp = new_strjoin(possible_paths[i], "/", path_and_cmd[0]);
		if (!access(tmp, F_OK))
			break ;
		if (possible_paths[i + 1])
			free(tmp);
	}
	if (!tmp || (!possible_paths[i] && !check_builtin(av)))
		ft_printf("pipex: %s: command not found\n", path_and_cmd[0]);
	free(path_and_cmd[0]);
	path_and_cmd[0] = tmp;
	path_list = set_path_list(path_list, path_and_cmd[0], path_and_cmd);
	return (path_list);
}

t_path	*handle_str_error(char **av, int i, int ac, t_path *path_list)
{
	ft_printf("pipex: %s: command not found\n", av[i]);
	if (i == ac - 2 && !is_here_doc(av[1]))
	{
		free_path_list(&path_list);
		unlink(".tmp");
		exit(EXIT_FAILURE);
	}
	path_list = set_path_list(path_list, NULL, NULL);
	return (path_list);
}

t_path	*choose_handle(char *av, char **envp, t_path *path_list)
{
	char	**path_and_cmd;
	char	**possible_paths;

	path_and_cmd = ft_split(av, ' ');
	if (is_dir(av))
	{
		if (access(path_and_cmd[0], F_OK) == -1)
			ft_printf("pipex: %s: No such file or directory\n",
				path_and_cmd[0]);
		path_list = set_path_list(path_list, path_and_cmd[0], path_and_cmd);
	}
	else
	{
		possible_paths = set_possible_paths(envp);
		path_list = find_path(path_list, possible_paths, av, path_and_cmd);
		free_matrix(possible_paths);
	}
	return (path_list);
}

/*Main function to define if the argv is an absolute path or not*/
t_path	*define_path(t_path *path_list, int ac, char **av, char **envp)
{
	int	i;

	i = 1;
	if (is_here_doc(av[1]))
		i = 2;
	while (av[++i] && i < ac - 1)
	{
		if (ft_str_error(av[i]))
			path_list = handle_str_error(av, i, ac, path_list);
		else
			path_list = choose_handle(av[i], envp, path_list);
	}
	return (path_list);
}
