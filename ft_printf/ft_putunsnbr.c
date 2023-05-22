/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:54:44 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/17 16:50:21 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsnbr(unsigned int n, unsigned int *size)
{
	if (n >= 10)
	{
		ft_putunsnbr((n / 10), size);
		ft_putunsnbr((n % 10), size);
	}
	else
		ft_putchar((n + 48), size);
}
