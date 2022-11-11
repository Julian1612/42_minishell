/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:57:10 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:18:57 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*s;
	char		*d;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (s < d)
		while (++i <= len)
			d[len - i] = s[len - i];
	while (len > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
