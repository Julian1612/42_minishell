/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:04:03 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 15:08:15 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL
#include <stdlib.h> // malloc

/// @brief	Allocates (with malloc(3)) and returns a new node.
///			The member variable ’content’ is initialized with
///			the value of the parameter ’content’. The variable
///			’next’ is initialized to NULL.
/// @param content 	The content to create the node with.
/// @return 	The new node
t_list	*ft_lstnew(void *content)
{
	t_list	*pointer;

	pointer = malloc(sizeof(t_list));
	if (pointer == NULL)
		return (NULL);
	pointer->content = content;
	pointer->next = NULL;
	return (pointer);
}
