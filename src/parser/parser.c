/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:03 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/13 10:52:43 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_data	*parser(char **token_arr)
{
	t_data	*head;
	int		cmd;

	cmd = cmd_counter(token_arr);
	head = create_list(cmd);
	init_list(head, token_arr);
	return (head);
}

int	cmd_counter(char **token_arr)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (token_arr[i] != NULL)
	{
		if (strcmp(token_arr[i], "|") == 0)
			count++;
		else if (strcmp(token_arr[i], ">") == 0)
			count++;
		else if (strcmp(token_arr[i], "<") == 0)
			count++;
		else if (strcmp(token_arr[i], ">>") == 0)
			count++;
		else if (strcmp(token_arr[i], "<<") == 0)
			count++;
		else if (strcmp(token_arr[i], ";") == 0)
			count++;
		i++;
	}
	return (count);
}
