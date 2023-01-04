/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:24:15 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/04 17:11:56 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int	handle_redir(t_data *node, char **token_arr, int *i)
// {
// 	if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
// 	{
// 			node->cmd_name = ft_strdup(token_arr[*i + 1]);
// 		node->cmd_line = (char **) malloc(sizeof(char *) * 2);
// 		if (node->cmd_line == NULL)
// 			return (1);
// 		node->cmd_line[0] = ft_strdup(token_arr[*i + 1]);
// 		node->cmd_line[1] = NULL;
// 		if (token_arr[*i][0] == '<')
// 		{
// 			if (token_arr[*i][1] == '<')
// 				node->operator = HEREDOC;
// 			else
// 				node->operator = IN;
// 		}
// 		else if (token_arr[*i][0] == '>')
// 		{
// 			if (token_arr[*i][1] == '>')
// 				node->operator = APPEND;
// 			else
// 				node->operator = OUT;
// 		}
// 		node->next = NULL;
// 		(*i) += 2;
// 	}
// 	if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
// 		return (0);
// 	while (token_arr[*i] != NULL && token_arr[*i][0] == '<' && token_arr[*i][0] == '>')
// 		append_node(node, token_arr, i, init_redir);
// 	append_node(node, token_arr, i, init_redir);
// 	return (0);
// }
int	init_redir(t_data *node, char **token_arr, int *i)
{
	node->cmd_name = ft_strdup(token_arr[*i + 1]);
	node->cmd_line = (char **) malloc(sizeof(char *) * 2);
	if (node->cmd_line == NULL)
		return (1);
	node->cmd_line[0] = ft_strdup(token_arr[*i + 1]);
	node->cmd_line[1] = NULL;
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
	return (0);
}

int	c_cmd(t_data **node, char **token_arr, int i)
{
	int	count;

	count = 0;
	while (token_arr[i] != NULL)
	{
		if (token_arr[i][0] == '>' || token_arr[i][0] == '<')
			append_node(node, token_arr, &i, init_redir);
		if (token_arr[i][0] == '|')
			break ;
		count++;
		i++;
	}
	return (count);
}

// Problem is here in the funvtion, node gtes not init correctly
int	init_cmd(t_data *node, char **token_arr, int *i)
{
	int	num_cmd;
	int	j;

	node->next = NULL;
	node->operator = get_op(token_arr, *i);
	num_cmd = c_cmd(&node, token_arr, *i);
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
		if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
			(*i) += 2;
		node->cmd_line[j] = ft_strdup(token_arr[*i]);
		if (node->cmd_line[j] == NULL)
			return (1);
		j++;
		(*i)++;
	}
	return (0);
}

int	handle_redir(t_data *node, char **token_arr, int *i)
{
	if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
	{
		init_redir(node, token_arr, i);
		if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
			return (0);
		while (token_arr[*i] != NULL && (token_arr[*i][0] == '<'
			|| token_arr[*i][0] == '>') && token_arr[*i][0] != '|')
			append_node(&node, token_arr, i, init_redir);
		append_node(&node, token_arr, i, init_cmd);
	}
	if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
		return (0);
	init_cmd(node, token_arr, i);
	return (0);
}
