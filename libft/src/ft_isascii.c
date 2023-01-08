/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:16:38 by dgross            #+#    #+#             */
/*   Updated: 2023/01/08 22:24:56 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
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
