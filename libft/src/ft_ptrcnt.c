/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:20:32 by dna               #+#    #+#             */
/*   Updated: 2022/11/26 22:31:42 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_ptrcnt(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}
