/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:00:42 by dgross            #+#    #+#             */
/*   Updated: 2022/09/09 13:43:37 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// counts the length of digit
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
