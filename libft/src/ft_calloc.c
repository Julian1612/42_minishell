/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:58:38 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 16:13:55 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <limits.h> // SIZE_MAX
#include <stdlib.h> // malloc

/// @brief 	allocates memory for an array of count elements of size bytes 
///			each and returns a pointer to the allocated memory.
/// @param count 	number of elements
/// @param size 	size of bytes for each element
/// @return	returns a pointer to the allacated memory
void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	if (count != 0 && size > (size_t)-1 / count)
		return (NULL);
	pointer = malloc (count * size);
	if (pointer == NULL)
		return (pointer);
	ft_bzero (pointer, count * size);
	return (pointer);
}
