/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:49:00 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:09:21 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief	Adds the node ’new’ at the beginning of the list.
/// @param lst 	The address of a pointer to the first link of
///				a list.
/// @param list 	The address of a pointer to the node to be
///					added to the list.
void	ft_lstadd_front(t_list **lst, t_list *list)
{
	list->next = *lst;
	*lst = list;
}
