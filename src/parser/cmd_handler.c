/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:24:12 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/09 16:29:45 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int	check(char **arr, int i)
// {
// 	while (arr[i] != NULL && arr[i][0] != '|')
// 	{
// 		if (arr[i][0] == '>')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	handle_cmd(t_data *node, char **token_arr, int *i, int pipe_nbr)
{
	int	num_cmd;
	int	j;

	if (token_arr[*i][0] == '|')
		(*i)++;
	(void) pipe_nbr;
	node->redir = get_pipe_nbr(token_arr, *i);
	node->operator = get_op(token_arr, *i);
	num_cmd = count_cmd(token_arr, *i);
	node->cmd_name = ft_strdup(token_arr[*i]);
	if (node->cmd_name == NULL)
		return (1);
	node->cmd_line = (char **) malloc(sizeof(char *) * (num_cmd + 1));
	if (node->cmd_line == NULL)
		return (1);
	node->cmd_line[num_cmd] = NULL;
	j = 0;
	while (j < num_cmd)
	{
		node->cmd_line[j] = ft_strdup(token_arr[*i]);
		if (node->cmd_line[j] == NULL)
			return (1);
		j++;
		(*i)++;
	}
	node->next = NULL;
	return (0);
}

int	get_op(char **token_arr, int i)
{
	int	flag;

	flag = 0;
	i++;
	if (token_arr[0][0] == '>')
		flag = 1;
	while (token_arr[i])
	{
		if (token_arr[i][0] == '>')
		{
			flag = 1;
			i++;
		}
		else if (flag == 1 && token_arr[i][0] == '|')
			return (CMD);
		else if (token_arr[i][0] == '|')
			return (PIPE);
		else if (token_arr[i] == NULL)
			return (CMD);
		else
			i++ ;
	}
	return (CMD);
}

int	count_cmd(char **token_arr, int i)
{
	int	count;

	count = 0;
	while (token_arr[i] != NULL)
	{
		if (token_arr[i][0] == '|' || token_arr[i][0] == '>'
			|| token_arr[i][0] == '<')
			break ;
		count++;
		i++;
	}
	return (count);
}
