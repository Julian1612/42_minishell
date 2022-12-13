/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:58:44 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:04:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief	Outputs the integer ’n’ to the given file
///			descriptor.
/// @param n 	The integer to output.
/// @param fd 	 The file descriptor on which to write.
void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = (long)n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = i * -1;
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		i = i % 10;
	}
	if (i < 10)
		ft_putchar_fd(i + 48, fd);
}
