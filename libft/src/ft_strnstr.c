/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:28 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:26:22 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)&haystack[i]);
	while (len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j + 1]);
			if (haystack[i + 1] != needle[j])
				j--;
		}
		i++;
		len--;
	}
	return (NULL);
}
