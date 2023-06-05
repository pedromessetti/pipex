/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:04:26 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/29 13:51:40 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates memory with malloc() and returns a substring
from the str s. The substring begins at index ’start’ and
is of maximum size len.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (0);
	if (len == 0 || start > ft_strlen(s))
	{
		subs = malloc(1);
		*subs = '\0';
		return (subs);
	}
	if (ft_strlen(s) - start < len)
		subs = malloc(ft_strlen(s) - start + 1);
	else
		subs = (char *)malloc(len + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		subs[i++] = s[start++];
	subs[i] = '\0';
	return (subs);
}

// int	main(void)
// {
// 	char const *s = "Lorem ipsum doloresmain";
// 	unsigned int start = 7;
// 	size_t len = 10;
// 	printf("String:%s:\n", s);
// 	printf("Start index:%d:\n", start);
// 	printf("Length:%zu:\n", len);
// 	printf("Substring:%s:\n", ft_substr(s, start, len));
// }