/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:03:01 by dgross            #+#    #+#             */
/*   Updated: 2022/09/09 13:44:30 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_putchar_fd

// counts the nbr lenght and returns it.
static int	ft_nbrlen(unsigned int digit)
{
	int	i;

	i = 0;
	if (digit == 0)
		return (i + 1);
	while (digit != 0)
	{
		digit /= 10;
		i++;
	}
	return (i);
}

// checks if digit is bigger or 10, if so
// digit gets div by 10 and passed again through the function.
// if digit is smaller then 10, the digit of digit will be printed
// recursively divides the digit by 10 and prints the remainder.

int	ft_putunsigned(unsigned int digit)
{
	int	len;

	len = ft_nbrlen(digit);
	if (digit >= 10)
	{
		ft_putunsigned(digit / 10);
		digit %= 10;
	}
	if (digit < 10)
		ft_putchar_fd(digit + '0', 1);
	return (len);
}
