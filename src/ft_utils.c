/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:24:57 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/16 14:34:36 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Updated version of strjoin for join 3 strings*/
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

/*Free the allocated memory for a bidimensional array*/
void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!*matrix || !**matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

/*Verify if the string only contains numeric chars
Return 1 if only contains num chars
Return 0 if contains other chars*/
int	str_is_num(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (!ft_isnum(s[i]))
			return (0);
	return (1);
}

/*
Return 1 if the str has only spaces or tabs
Return 0 if the str has other chars
*/
int	ft_str_error(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
	}
	return (1);
}
