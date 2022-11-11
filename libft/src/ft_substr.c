/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:27:40 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:28:59 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // malloc

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
	{
		str = (char *)malloc (sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (i > len)
		len = len + 1;
	else
		len = i + 2;
	str = (char *)malloc (sizeof(char) * (len));
	if (str == NULL)
		return (str);
	ft_strlcpy(str, s + start, len);
	return (str);
}
