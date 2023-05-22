/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:55:37 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/17 16:50:56 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, unsigned int *size)
{
	if (n == -2147483648)
	{
		ft_putchar('-', size);
		ft_putchar('2', size);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', size);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr((n / 10), size);
		ft_putnbr((n % 10), size);
	}
	else
		ft_putchar((n + 48), size);
}
