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
	printf("redir token_arr[%d] = %s\n", *i, token_arr[*i]);
	return (0);
}

int	append_redir(t_data **head, char **token_arr, int *i, int (*init)(t_data *, char **, int *))
{
	t_data	*tmp;

	tmp = NULL;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = create_node(token_arr, i, init);
	if (tmp->next == NULL)
		return (1);
	return (0);
}

// Das Problem is hier das i nicht richtig mit gezáhlt wird
int	c_cmd(t_data **node, char **token_arr, int i)
{
	int	count;

	count = 0;
	while (token_arr[i] != NULL)
	{
		printf("pre c_cmd i: %d\n", i);
		if (token_arr[i][0] == '>' || token_arr[i][0] == '<')
			append_redir(node, token_arr, &i, init_redir);
		printf("past c_cmd i: %d\n", i);
		if (token_arr[i] == NULL || token_arr[i][0] == '|')
			break ;
		count++;
		i++;
	}
	return (count);
}

int	init_cmd(t_data *node, char **token_arr, int *i)
{
	int	num_cmd;
	int	j;

	node->next = NULL;
	node->operator = get_op(token_arr, *i);
	// printf("pre c_cmd i: %d\n", *i);
	num_cmd = c_cmd(&node, token_arr, *i);
	// printf("past c_cmd i: %d\n", *i);
	node->cmd_name = ft_strdup(token_arr[*i]);
	if (node->cmd_name == NULL)
		return (1);
	node->cmd_line = (char **) malloc(sizeof(char *) * (num_cmd + 1));
	if (node->cmd_line == NULL)
		return (1);
	node->cmd_line[num_cmd] = NULL;
	j = 0;
	// die schleife bis zum schluss laufen lassen also bis pipw oder
	while (j < num_cmd)
	{
		printf("OGGGGGGtoken_arr[%d] = %s\n", *i, token_arr[*i]);
		if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
		{
			printf("hi\n");
			(*i) += 2;
		}
		node->cmd_line[j] = ft_strdup(token_arr[*i]);
		printf("i = %d\n", *i);
		if (node->cmd_line[j] == NULL)
			return (1);
		j++;
		(*i)++;
	}
	while (token_arr[*i] != NULL && token_arr[*i][0] != '|')
		(*i)++;
	return (0);
}

//// !!!!!!!!!
int	handle_redir(t_data *node, char **token_arr, int *i)
{
	int	flag;

	flag = 0;
	printf("GGtoken_arr[%d] = %s\n", *i, token_arr[*i]);
	if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
	{
		init_redir(node, token_arr, i);
		printf("OGtoken_arr[%d] = %s\n", *i, token_arr[*i]);
		if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
			return (0);

		while (token_arr[*i] != NULL && (token_arr[*i][0] == '<'
			|| token_arr[*i][0] == '>') && token_arr[*i][0] != '|')
		{
			printf("while\n");
			append_node(&node, token_arr, i, init_redir);
		}
		// append_node(&node, token_arr, i, init_cmd);
		flag = 1;
	}
	if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
		return (0);
	if (flag == 1)
	{
		printf("hi\n");
		append_node(&node, token_arr, i, init_cmd);
	}
	else
		init_cmd(node, token_arr, i);
	printf("OPtoken_arr[%d] = %s\n", *i, token_arr[*i]);
	if (token_arr[*i][0] == '|')
		(*i)++;
	return (0);
}
