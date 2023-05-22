/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:54:12 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/18 10:09:01 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr(unsigned long int n, unsigned int *size)
{
	if (!n)
	{
		ft_putstr("(nil)", size);
		return ;
	}
	if (n < 16)
	{
		ft_putstr("0x", size);
		ft_putchar(HEX_LOW[n % 16], size);
		return ;
	}
	ft_putaddr(n / 16, size);
	ft_putchar(HEX_LOW[n % 16], size);
}
