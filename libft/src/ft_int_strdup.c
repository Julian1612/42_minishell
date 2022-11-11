/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:44:27 by dgross            #+#    #+#             */
/*   Updated: 2022/10/05 15:32:21 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	*ft_int_strdup(const int *s, int len)
{
	int	*dup;

	dup = malloc(sizeof(int) * len);
	if (!dup)
		return (0);
	ft_int_memcpy(dup, s, len);
	return (dup);
}
