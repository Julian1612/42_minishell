/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:16:20 by dgross            #+#    #+#             */
/*   Updated: 2022/12/31 20:57:40 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isnumber(const char *str, int i, int sign, long int result1)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result1 * sign > 2147483647)
			return (0);
		if (result1 * sign < -2147483648)
			return (0);
		result1 = 10 * result1 + (str[i] - '0');
		i++;
	}
	return (result1);
}

/// @brief	 Converts the initial portion of the string pointed to
///   		 by str to int representation.
/// @param str 	pointer to the null-terminated byte string to be interpreted
/// @return Integer value corresponding to the contents of str on success.
///			If no conversion can be performed, ​0​ is returned.
int	ft_atoi(const char	*str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r'
		|| str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	result = isnumber(str, i, sign, result) * sign;
	return (result);
}
