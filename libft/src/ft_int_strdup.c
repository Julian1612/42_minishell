/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:44:27 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 16:34:51 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> // malloc

/// @brief	returns a pointer to a new array which is
///			a duplicate of the array s.
/// @param s the array to duplicate
/// @param len the length of the array
/// @return the duplicated array
int	*ft_int_strdup(const int *s, int len)
{
	int	*dup;

	dup = malloc(sizeof(int) * len);
	if (!dup)
		return (0);
	ft_int_memcpy(dup, s, len);
	return (dup);
}
