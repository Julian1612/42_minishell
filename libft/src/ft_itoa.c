/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:35:43 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:08:41 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL size_t
#include <stdlib.h> // malloc

static int	ft_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	len;
	long int	z;

	z = n;
	len = ft_len(n);
	if (z < 0)
	{
		z = z * -1;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		len--;
		str[len] = z % 10 + '0';
		z = z / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
