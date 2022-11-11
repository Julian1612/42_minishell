/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:16 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:25:02 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	void	*pdst;
	void	*psrc;

	pdst = (void *)dst;
	psrc = (void *)src;
	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	if (len + 1 < dstsize)
		ft_memcpy(pdst, psrc, len + 1);
	else if (len != 0)
	{
		ft_memcpy(pdst, psrc, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len);
}
