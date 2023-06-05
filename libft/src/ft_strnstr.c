/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:21:12 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/29 15:44:20 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Locates the first occurrence of the null-terminated
str little in the str big, where not more than len char are searched.

Returns a pointer to the first char of the first occurrence of little.
If little occurs nowhere in big, NULL is returned.
If little is empty, big is returned.*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *p = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15);

// 	if (p == NULL)
// 		printf("OK");
// 	else
// 		printf("KO");
// }