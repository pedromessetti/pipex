#include "pipex.h"

void check_ac(int ac)
{
	if (ac == 5)
		return ;
	else if(ac < 5)
	{
		ft_printf("pipex: too few arguments\n");
		exit(1);
	}
	else if (ac > 5)
	{
		ft_printf("pipex: too many arguments\n");
		exit(1);
	}
}
