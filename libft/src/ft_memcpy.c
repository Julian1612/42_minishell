/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:54:47 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 16:23:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL

/// @brief	copies n bytes from memory area src to
///			memory area dest.  The memory areas must not overlap.
/// @param dst pointer to the dst to write to
/// @param src pointer to the src to copy from
/// @param n number of bytes to copy
/// @return pointer to the dst
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*b;
	char		*c;

	c = (char *)dst;
	b = (const char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n > i)
	{
		c[i] = b[i];
		i++;
	}
	return (dst);
}
