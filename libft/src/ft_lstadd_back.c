/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:49:40 by dgross            #+#    #+#             */
/*   Updated: 2022/08/19 15:39:54 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

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
