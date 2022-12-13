/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:17:43 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:19:27 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief	Iterates the list ’lst’ and applies the function
///			’f’ on the content of each node.
/// @param lst 	The address of a pointer to a node. 
/// @param f 	The address of the function used to iterate on
///				the list. 
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*pointer;

	pointer = NULL;
	while (lst)
	{
		pointer = lst->next;
		f(lst->content);
		lst = pointer;
	}
}
