/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:16:24 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 16:00:46 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t

/// @brief 	writes n zeroed bytes to the string s.  If n is zero,
///			bzero() does nothing.
/// @param s	pointer to the memory to write to
/// @param n 	size of the pointer
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
