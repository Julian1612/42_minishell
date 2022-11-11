/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:16:24 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:01:07 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;

	c = 0;
	ptr = s;
	while (n)
	{
		*ptr = c;
		ptr++;
		n--;
	}
}
