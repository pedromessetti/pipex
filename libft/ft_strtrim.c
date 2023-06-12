/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:39:57 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/29 15:41:46 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates memory with malloc() and returns a copy of
s1 with the characters specified in ’set’ removed
from the beginning and the end of the string,
or NULL if the allocation fails.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	strim = ft_substr(s1, start, (end - start));
	return (strim);
}

// int	main(void)
// {
// 	char const *s1 = "abcHello-Worldabc";
// 	char const *set = "abc";

// 	printf("string:%s:\n", s1);
// 	printf("set of char:%s:\n", set);
// 	printf("string trimmed:%s:\n", ft_strtrim(s1, set));
// }