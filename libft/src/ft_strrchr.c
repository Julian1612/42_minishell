/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:07:10 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:27:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

char	*ft_strrchr(const char *s, int c)
{
	int		b;

	c = c % 128;
	b = ft_strlen(s);
	while (b >= 0)
	{
		if (s[b] == c)
			return ((char *)(s + b));
		b--;
	}
	return (NULL);
}
