/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:16:38 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 16:42:42 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 	checks whether c is a 7-bit unsigned char 
///			value that fits into the ASCII character set.
/// @param c 	the value to check
/// @return 1 if its a ascii character, else 0
int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	else
		return (0);
}
