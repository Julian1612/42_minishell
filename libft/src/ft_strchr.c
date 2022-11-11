/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:10 by dgross            #+#    #+#             */
/*   Updated: 2022/07/27 17:59:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

char	*ft_strchr(const char *s, int c)
{
	char	i;
	int		b;
	int		j;

	j = 0;
	i = c;
	b = ft_strlen(s);
	while (j <= b)
	{
		if (s[j] == i)
			return ((char *)s + j);
		j++;
	}
	return (NULL);
}
