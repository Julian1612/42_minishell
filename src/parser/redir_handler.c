/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:24:15 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/09 19:18:18 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	check_out(char **arr, int i)
{
	while (arr[i] != NULL && arr[i][0] != '|')
	{
		if (arr[i][0] == '>')
			return (1);
		i++;
	}
	return (0);
}

int	process_redir(t_data *node, char **token_arr, int *i, int *flag)
{
	if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
	{
		init_redir(node, token_arr, i);
		if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
			return (1);
		while (token_arr[*i] != NULL && (token_arr[*i][0] == '<'
			|| token_arr[*i][0] == '>') && token_arr[*i][0] != '|')
			append_node(&node, token_arr, i, init_redir);
		(*flag) = 1;
	}
	return (0);
}

int	handle_redir(t_data *node, char **token_arr, int *i)
{
	int	flag;
	int	flag1;

	flag = 0;
	flag1 = 0;
	node->redir = get_pipe_nbr(token_arr, *i);
	if (check_out(token_arr, *i))
		flag = 1;
	if (process_redir(node, token_arr, i, &flag1))
		return (0);
	if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
		return (0);
	if (flag1 == 1)
		append_node(&node, token_arr, i, init_cmd);
	else
		init_cmd(node, token_arr, i);
	if (token_arr[*i] == NULL)
		return (0);
	if (token_arr[*i][0] == '|' && flag)
		append_node(&node, token_arr, i, init_null);
	if (token_arr[*i][0] == '|')
		(*i)++;
	return (0);
}

int	init_data(t_data *node, char **token_arr, int *i)
{
	node->cmd_name = ft_strdup(token_arr[*i + 1]);
	node->cmd_line = (char **) malloc(sizeof(char *) * 2);
	if (node->cmd_line == NULL)
		return (1);
	node->cmd_line[0] = ft_strdup(token_arr[*i + 1]);
	node->cmd_line[1] = NULL;
	return (0);
}

int	init_null(t_data *node, char **token_arr, int *i)
{
	node->cmd_name = NULL;
	node->cmd_line = NULL;
	node->operator = PIPE;
	node->redir = get_pipe_nbr(token_arr, *i);
	node->next = NULL;
	return (0);
}
