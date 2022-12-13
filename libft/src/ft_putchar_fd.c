/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:08:27 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:01:46 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h> // write

/// @brief	Outputs the character ’c’ to the given file
///			descriptor.
/// @param c 	The character to output.
/// @param fd 	 The file descriptor on which to write.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
