/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:37:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/29 13:06:33 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Fills the first n bytes of the memory
area pointed to by s with the constant byte c.

Returns a pointer to the memory area s.*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
}

// int	main(void)
// {
// 	char p[12] = "Hello World";
// 	int c = '-';

// 	printf("before:%s:\n", p);
// 	ft_memset(p, c, 10);
// 	printf("after:%s:\n", p);
// }