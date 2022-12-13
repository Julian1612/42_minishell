/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:11:00 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:10:35 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

/// @brief	Counts the number of nodes in a list.
/// @param lst 	The beginning of the list.
/// @return 	The length of the list
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (lst == NULL)
		return (i);
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
	if (lst->next == NULL)
		i++;
	return (i);
}	
