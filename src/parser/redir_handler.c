/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:24:15 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/06 23:59:49 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	handle_redir(t_data *node, char **token_arr, int *i)
{
	int	flag;

	flag = 0;
	if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
	{
		init_redir(node, token_arr, i);
		if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
			return (0);
		while (token_arr[*i] != NULL && (token_arr[*i][0] == '<'
			|| token_arr[*i][0] == '>') && token_arr[*i][0] != '|')
			append_node(&node, token_arr, i, init_redir);
		flag = 1;
	}
	if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
		return (0);
	if (flag == 1)
		append_node(&node, token_arr, i, init_cmd);
	else
		init_cmd(node, token_arr, i);
	if (token_arr[*i] == NULL)
		return (0);
	if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
		(*i)++;
	return (0);
}

int	init_redir(t_data *node, char **token_arr, int *i)
{
	init_data(node, token_arr, i);
	if (token_arr[*i][0] == '<')
	{
		if (token_arr[*i][1] == '<')
			node->operator = HEREDOC;
		else
			node->operator = IN;
	}
	else if (token_arr[*i][0] == '>')
	{
		if (token_arr[*i][1] == '>')
			node->operator = APPEND;
		else
			node->operator = OUT;
	}
	node->next = NULL;
	(*i) += 2;
	if (token_arr[*i] == NULL)
		return (0);
	if (token_arr[*i][0] == '|')
		append_node(&node, token_arr, i, init_test);
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

int	init_test(t_data *node, char **token_arr, int *i)
{
	(void) token_arr;
	(void) *i;
	node->cmd_name = NULL;
	node->cmd_line = NULL;
	node->operator = PIPE;
	node->next = NULL;
	return (0);
}
