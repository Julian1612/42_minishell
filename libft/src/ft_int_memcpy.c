/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:46:19 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 16:23:36 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief	[INT] copies n bytes from memory area src to
///			memory area dest.  The memory areas must not overlap.
/// @param dst pointer to the dst to write to
/// @param src pointer to the src to copy from
/// @param n number of bytes to copy
/// @return pointer to the dst
void	*ft_int_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n && (dst || src))
	{
		*((unsigned int *)dst + i) = *((unsigned int *)src + i);
		i++;
		i++;
	}
	return (dst);
}
