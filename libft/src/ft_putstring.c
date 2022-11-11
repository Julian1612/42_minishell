/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:07:53 by dgross            #+#    #+#             */
/*   Updated: 2022/09/09 13:44:25 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_putchar_fd

#include <stddef.h> // size_t NULL

// prints out every char in the string.
// If the string is empty, a (null) is printed and returned.
void	ft_putstring(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstring("(null)");
		return ;
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}
