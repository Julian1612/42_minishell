/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:33:28 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:10:40 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

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
