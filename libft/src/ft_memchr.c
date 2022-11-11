/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:52:10 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:17:14 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*b;
	unsigned char	k;

	k = (unsigned char)c;
	b = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (b[i] == k)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
