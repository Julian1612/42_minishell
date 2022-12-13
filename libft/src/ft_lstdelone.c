/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:47:21 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:15:22 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h> // free

/// @brief	Takes as a parameter a node and frees the memory of
///			the node’s content using the function ’del’ given
///			as a parameter and free the node. The memory of
///			’next’ must not be freed.
/// @param lst 	The node to free.
/// @param del 	The address of the function used to delete
///				the content.
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
