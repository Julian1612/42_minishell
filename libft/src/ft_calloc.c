/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:58:38 by dgross            #+#    #+#             */
/*   Updated: 2022/08/11 10:17:00 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <limits.h> // SIZE_MAX
#include <stdlib.h> // malloc

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
