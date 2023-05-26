#include "pipex.h"

t_path	*set_path_list(t_path *path_list, char *path,	char **path_and_cmd)
{
	if (!path_list)
		path_list = add_path(path, path_and_cmd);
	else
		add_tail(&path_list, add_path(path, path_and_cmd));
	return (path_list);
}

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

t_path	*find_path(t_path *path_list, char **possible_paths, char *av,	char **path_and_cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (possible_paths[++i])
	{
		tmp = new_strjoin(possible_paths[i], "/", path_and_cmd[0]);
		if (!access(tmp, F_OK))
			break ;
		free(tmp);
	}
	if (!*tmp)
	{
		ft_printf("pipex: %s: command not found\n", av);
		return (NULL);
	}
	path_and_cmd[0] = tmp;
	path_list = set_path_list(path_list, tmp, path_and_cmd);
	return (path_list);
}

t_path	*absolute_path(t_path *path_list, char *av, char **path_and_cmd)
{
	char	*path;

	path = ft_strdup(av);
	if (access(av, F_OK) != -1)
	{
		path_and_cmd[0] = path;
		path_and_cmd[1] = NULL;
		path_list = set_path_list(path_list, path, path_and_cmd);
		return (path_list);
	}
	else
	{
		ft_printf("pipex erro: %s: command not found\n", av);
		free(path);
		return (NULL);
	}
}

t_path	*define_path(t_path *path_list, int ac, char **av, char **envp)
{
	char	**path_and_cmd;
	char	**possible_paths;
	int		i;

	i = 1;
	while (av[++i] && i < ac - 1)
	{
		if (!*av[i])
			exit(EXIT_FAILURE);
		path_and_cmd = ft_split(av[i], ' ');
		if (!(ft_strncmp(av[i], "/", 1)) || !(ft_strncmp(av[i], "./", 2)))
			path_list = absolute_path(path_list, av[i], path_and_cmd);
		else
		{
			possible_paths = set_possible_paths(envp);
			path_list = find_path(path_list, possible_paths, av[i],
					path_and_cmd);
			free_matrix(possible_paths);
		}
	}
	return (path_list);
}
