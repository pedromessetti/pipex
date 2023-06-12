/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:14 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/29 13:07:55 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns a pointer to the first occurrence of the char c in the str.*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;
	int				i;

	a = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)s + i);
		i++;
	}
	if (a == '\0')
		return ((char *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	const char *s = "Hello World!";
// 	int c = ' ';

// 	printf("string:%s:\n", s);
// 	printf("char:%d:\n", c);
// 	printf("first occurence:%s:\n", ft_strchr(s, c));
// }