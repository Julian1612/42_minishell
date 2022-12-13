/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:13:40 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:22:14 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

/// @brief	Iterates the list ’lst’ and applies the function
///			’f’ on the content of each node. Creates a new
///			list resulting of the successive applications of
///			the function ’f’. The ’del’ function is used to
///			delete the content of a node if needed.
/// @param lst 	The address of a pointer to a node.
/// @param f 	The address of the function used to iterate on
///				the list.
/// @param del 	The address of the function used to delete
///				the content of a node if needed.
/// @return		The new list.
///				NULL if the allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	start = 0;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new);
		lst = lst->next;
	}
	return (start);
}
