/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:59:09 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 14:57:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // malloc

/// @brief	Applies the function ’f’ to each character of the
///			string ’s’, and passing its index as first argument
///			to create a new string (with malloc(3)) resulting
///			from successive applications of ’f’.
/// @param s 	The string on which to iterate
/// @param f 	The function to apply to each character.
/// @return	The string created from the successive applications
///			of ’f’. Returns NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*pointer;

	i = 0;
	if (!s)
		return (NULL);
	pointer = malloc (sizeof(char) * ft_strlen(s) + 1);
	if (pointer == NULL)
		return (NULL);
	while (s[i])
	{
		pointer[i] = (*f)(i, s[i]);
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
