/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:54:47 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:18:35 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL

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
