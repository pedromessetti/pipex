/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:56:48 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/18 09:35:48 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int n, char *base, unsigned int *size)
{
	long int	li;
	int			baselen;

	li = n;
	baselen = 0;
	while (base[baselen])
		baselen++;
	if (li / baselen == 0)
		ft_putchar(base[li % baselen], size);
	else
	{
		ft_putnbr_base(li / baselen, base, size);
		ft_putchar(base[li % baselen], size);
	}
}
