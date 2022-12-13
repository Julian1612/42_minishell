/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:00:42 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 16:18:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief	Counts the length of digit
/// @param digit the number to count
/// @return length of digit
int	ft_countnbr(int digit)
{
	int	i;

	i = 0;
	if (digit < 0)
		i++;
	if (digit == 0)
		return (i + 1);
	while (digit != 0)
	{
		digit = digit / 10;
		i++;
	}
	return (i);
}
