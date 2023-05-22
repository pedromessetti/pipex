/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:54:47 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/18 09:25:31 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
