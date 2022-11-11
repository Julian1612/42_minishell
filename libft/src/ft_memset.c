/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:06 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:19:29 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	char	s;

	str = (char *)b;
	s = c;
	while (len)
	{
		*str = s;
		str++;
		len--;
	}
	return (b);
}
