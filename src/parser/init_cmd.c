/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:23:46 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/09 16:19:47 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	init_cmd(t_data *node, char **token_arr, int *i)
{
	int	num_cmd;

	node->next = NULL;
	node->redir = get_pipe_nbr(token_arr, *i);
	node->operator = get_op(token_arr, *i);
	num_cmd = c_cmd(&node, token_arr, *i);
	node->cmd_name = ft_strdup(token_arr[*i]);
	if (node->cmd_name == NULL)
		return (1);
	node->cmd_line = (char **) malloc(sizeof(char *) * (num_cmd + 1));
	if (node->cmd_line == NULL)
		return (1);
	node->cmd_line[num_cmd] = NULL;
	init_cmd_line(node, token_arr, i, num_cmd);
	return (0);
}

int	init_cmd_line(t_data *node, char **token_arr, int *i, int num_cmd)
{
	int	j;

	j = 0;
	while (j < num_cmd)
	{
		if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
		{
			(*i) += 2;
			continue ;
		}
		node->cmd_line[j] = ft_strdup(token_arr[*i]);
		if (node->cmd_line[j] == NULL)
			return (1);
		j++;
		(*i)++;
	}
	while (token_arr[*i] != NULL && token_arr[*i][0] != '|')
		(*i)++;
	return (0);
}
