/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:20:56 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/30 14:07:19 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns a pointer to  the matched character
or NULL if the character is not found.*/
char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;
	int				i;

	a = c;
	i = ft_strlen(s);
	if (a == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *s = "Hello world porra!";
// 	int c = 'o';

// 	printf("string:%s:\n", s);
// 	printf("char:%d:\n", c);
// 	printf("first occurence:%s:\n", ft_strrchr(s, c));
// }