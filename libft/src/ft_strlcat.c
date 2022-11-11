/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:13 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:24:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	b;
	size_t	j;
	char	*s;

	i = ft_strlen(dst);
	b = ft_strlen(src);
	j = 0;
	s = (char *)src;
	if (i <= size)
		b = b + i;
	else
		b = b + size;
	if (size > i)
	{
		while (s[j] != '\0' && i < size - 1)
		{
			dst[i] = s[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (b);
}
