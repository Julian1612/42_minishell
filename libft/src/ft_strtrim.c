/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:50:05 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 14:58:21 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // malloc

static size_t	ft_front(char const *s1, char const *set, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_back(char const *s1, char const *set, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		if (ft_strchr(set, s1[j - i - 1]) == 0)
			break ;
		i++;
	}
	return (j - i);
}

/// @brief	Allocates (with malloc(3)) and returns a copy of
///			’s1’ with the characters specified in ’set’ removed
///			from the beginning and the end of the string.
/// @param s1 	The string to be trimmed.
/// @param set 	The reference set of characters to trim
/// @return	The trimmed string.
///			NULL if the allocation fails
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		front;
	int		back;
	int		size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	size = ft_strlen(s1);
	front = ft_front(s1, set, size);
	back = ft_back(s1, set, size);
	if (front >= back)
		return (ft_strdup(""));
	trim = malloc (sizeof(char) * (back - front + 1));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy (trim, s1 + front, back - front + 1);
	return (trim);
}
