/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:39:07 by dgross            #+#    #+#             */
/*   Updated: 2022/10/17 23:08:17 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // malloc

char	*gnl_strchr(char *s, int c)
{
	char	i;
	int		b;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	i = c;
	b = gnl_strlen(s);
	while (j <= b)
	{
		if (s[j] == i)
			return ((char *)s + j);
		j++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*string;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	string = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			string[i] = s1[i];
	while (s2[j] != '\0')
		string[i++] = s2[j++];
	string[gnl_strlen(s1) + gnl_strlen(s2)] = '\0';
	free(s1);
	return (string);
}

size_t	gnl_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
