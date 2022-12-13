/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:00:59 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 16:36:29 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // malloc free

/// @brief	returns a pointer to a new string which is
///			a duplicate of the string s1.
/// @param s1 the string to duplicate
/// @return the duplicated string
char	*ft_strdup(const char *s1)
{	
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + 1;
	str = malloc (sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len);
	return (str);
}
