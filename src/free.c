/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:48:24 by dgross            #+#    #+#             */
/*   Updated: 2022/12/30 16:06:31 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	free_data(t_data *head)
{
	t_data	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free_double(tmp->cmd_line);
		free(tmp->cmd_name);
		free(tmp);
	}
}

void	free_shell(t_koopa *head)
{
	t_koopa	*tmp;

	if (head != NULL)
	{
		tmp = head;
		free_double(tmp->envp);
		free(tmp);
	}
}
