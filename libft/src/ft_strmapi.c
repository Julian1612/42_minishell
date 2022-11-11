/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:59:09 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:25:46 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // malloc

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
