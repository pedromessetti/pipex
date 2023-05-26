/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:24:57 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/26 15:06:30 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*new_strjoin(char const *s1, char const *s2, char const *s3)
{
	char	*new_s;
	size_t	i;
	size_t	j;
	size_t	k;

	new_s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	if (!new_s)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_s[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_s[i++] = s2[j];
	k = -1;
	while (s3[++k])
		new_s[i++] = s3[k];
	new_s[i] = '\0';
	return (new_s);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!*matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}
