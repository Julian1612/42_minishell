/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:48:24 by dgross            #+#    #+#             */
/*   Updated: 2023/01/06 18:21:24 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h> // free
#include <stdio.h> 

void	free_data(t_data *head)
{
	t_data	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp->cmd_line != NULL)
		{
			free_double(tmp->cmd_line);
			free(tmp->cmd_name);
		}
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
