/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:49:40 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:13:34 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

/// @brief	Adds the node ’new’ at the end of the list.
/// @param lst 	The address of a pointer to the first link of
///				a list.
/// @param list 	The address of a pointer to the node to be
///					added to the list
void	ft_lstadd_back(t_list **lst, t_list *list)
{
	t_list	*b;

	b = NULL;
	if (*lst == NULL)
		*lst = list;
	else
	{
		b = ft_lstlast(*lst);
		b->next = list;
	}
}
