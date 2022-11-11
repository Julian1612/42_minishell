/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:00:59 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:46:04 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // malloc free

char	*ft_strdup(const char *s1)
{	
	char	*pointer;
	size_t	len;

	len = ft_strlen(s1) + 1;
	pointer = malloc (sizeof(char) * len);
	if (pointer == NULL)
		return (NULL);
	ft_memcpy(pointer, s1, len);
	return (pointer);
}
