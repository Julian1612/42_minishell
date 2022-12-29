/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:48:24 by dgross            #+#    #+#             */
/*   Updated: 2022/12/29 08:59:36 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	free_data(t_data *head)
{
	t_data	*tmp;

	if (head != NULL)
	{
		tmp = head;
		head = head->next;
		free_double(tmp->cmd_line);
		free(tmp);
	}
}
