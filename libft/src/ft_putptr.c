/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:15:12 by dgross            #+#    #+#             */
/*   Updated: 2022/09/09 13:44:19 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // ft_puthexnbr
#include "libft.h" // ft_putstr_fd ft_putnbr_fd

// prints 0x (notation for Hex number).
// checks if ptr is empty if so it prints 0 and
// returns a "0" string otherwise ptr will be calculated into hex 
int	ft_putptr(unsigned long int ptr, const char *str)
{
	ft_putstr_fd("0x", 1);
	if (ptr == 0)
	{
		ft_putnbr_fd(0, 1);
		return (2);
	}
	return (ft_puthexnbr(ptr, str));
}
