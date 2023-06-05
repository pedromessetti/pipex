/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:54:44 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/02 10:24:26 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
