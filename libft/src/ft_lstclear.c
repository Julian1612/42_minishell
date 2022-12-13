/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:33:28 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:18:11 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

/// @brief	Deletes and frees the given node and every
///			successor of that node, using the function ’del’
/// 		and free(3).
///			Finally, the pointer to the list must be set to
///			NULL.
/// @param lst 	The address of a pointer to a node.
/// @param del 	The address of the function used to delete
///				the content of the node.
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pointer;

	pointer = NULL;
	while (*lst)
	{
		pointer = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = pointer;
	}
}
