/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:56:48 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/02 10:24:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
