/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:15:58 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:00:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t

/// @brief	Applies the function ’f’ on each character of
///			the string passed as argument, passing its index
///			as first argument. Each character is passed by
///			address to ’f’ to be modified if necessary.
/// @param s 	The string on which to iterate.
/// @param f 	The function to apply to each character.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
