/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:21:56 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/12 16:44:05 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory with malloc() and returns a new
string, which is the result of the concatenation
of s1 and s2, or NULL if the allocation fails. */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = ft_calloc((len_s1 + len_s2 + 1), sizeof (char));
	if (!new_s)
		return (NULL);
	if (s1)
		ft_strlcpy(new_s, s1, len_s1 + 1);
	if (s2)
		ft_strlcat(new_s, s2, len_s1 + len_s2 + 1);
	return (new_s);
}
