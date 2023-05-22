#include "pipex.h"

void	start_child_process(char **av)
{
	int	file1_fd;
	int	file2_fd;

	file1_fd = open(av[1], O_RDONLY);
	if (file1_fd == -1)
	{
		ft_printf("pipex: %s: Archive not found\n", av[1]);
		exit(1);
	}
	file2_fd = open(av[4], O_CREAT | O_WRONLY, 0644);
	if (file2_fd == -1)
	{
		ft_printf("pipex: Error opening/creating the file");
		exit(1);
	}
	close(file1_fd);
	close(file2_fd);
}
