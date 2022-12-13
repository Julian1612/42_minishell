/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:41:13 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:11:54 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

/// @brief	Returns the last node of the list.
/// @param lst 	The beginning of the list.
/// @return 	Last node of the list
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
