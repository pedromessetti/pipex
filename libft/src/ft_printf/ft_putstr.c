/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:54:47 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/02 10:24:23 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s, unsigned int *size)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", size);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], size);
		i++;
	}
}
