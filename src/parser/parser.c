/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:03 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/04 17:12:54 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	list_test(t_data *cmd_list)
{
	t_data	*cur;
	cur = cmd_list;
	int g = 1;
	int y = 0;

	while (cur != NULL)
	{
		printf("\e[37m----------------------\n");
		printf("\e[106m----------%d-----------\e[49m\n", g);
		printf("\e[37m----------------------\n");
		printf("\e[32mcmd: %s\n", cur->cmd_name);
		printf("\e[37m~~~~~~~~~~~~~~~~~~~~~~\n");
		while (cur->cmd_line[y] != NULL)
		{
			printf("\e[34m%d.%d. cmd_line: %s\n", g, y, cur->cmd_line[y]);
			y++;
		}
		y = 0;
		printf("\e[37m~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\e[95moperator: %d\033[0m\n", cur->operator);
		cur = cur->next;
		g++;
	}
}

int	get_op(char **token_arr, int i)
{
	i++;
	while (token_arr[i])
	{
		if (token_arr[i][0] == '|')
			return (PIPE);
		else if (token_arr[i][0] == '<')
			return (CMD);
		else if (token_arr[i][0] == '>')
			return (CMD);
		else if (token_arr[i] == NULL)
			return (CMD);
		else
			i++ ;
	}
	return (CMD);
}

// int	handle_redir(t_data *node, char **token_arr, int *i)
// {
// 	node->cmd_name = ft_strdup(token_arr[*i + 1]);
// 	node->cmd_line = (char **) malloc(sizeof(char *) * 2);
// 	if (node->cmd_line == NULL)
// 		return (1);
// 	node->cmd_line[0] = ft_strdup(token_arr[*i + 1]);
// 	node->cmd_line[1] = NULL;
// 	if (token_arr[*i][0] == '<')
// 	{
// 		if (token_arr[*i][1] == '<')
// 			node->operator = HEREDOC;
// 		else
// 			node->operator = IN;
// 	}
// 	else if (token_arr[*i][0] == '>')
// 	{
// 		if (token_arr[*i][1] == '>')
// 			node->operator = APPEND;
// 		else
// 			node->operator = OUT;
// 	}
// 	node->next = NULL;
// 	(*i) += 2;
// 	return (0);
// }

// int	init_node(t_data *node, char **token_arr, int *i)
// {
// 	if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>' )
// 	{
// 		if (handle_redir(node, token_arr, i))
// 			return (1);
// 	}
// 	else
// 	{
// 		if (handle_cmd(node, token_arr, i))
// 			return (1);
// 	}
// 	return (0);
// }

int	handle_cmd(t_data *node, char **token_arr, int *i)
{
	int	num_cmd;
	int	j;

	if (token_arr[*i][0] == '|')
		(*i)++;
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

int	redir_check(char **token_arr, int i)
{
	int	counter;

	counter = 0;
	while (token_arr[i] != NULL && token_arr[i][0] != '|')
	{
		if (token_arr[i][0] == '<' || token_arr[i][0] == '>')
			counter++;
		i++;
	}
	return (counter);
}

int	init_content(t_data *node, char **token_arr, int *i)
{
	int	redirection;

	redirection = redir_check(token_arr, *i);
	printf("token_arr[%d]: %s\n", *i, token_arr[*i]);
	if (redirection > 0)
	{
		printf("redirection flag: %d\n", redirection);
		if (handle_redir(node, token_arr, i))
			return (1);
	}
	else
	{
		if (handle_cmd(node, token_arr, i))
			return (1);
	}
	return (0);
}

t_data	*create_node(char **token_arr, int *i, int (*init)(t_data *, char **, int *))
{
	t_data	*new_node;

	new_node = (t_data *) malloc(sizeof(t_data));
	if (new_node == NULL)
		return (NULL);
	if (init(new_node, token_arr, i))
		return (NULL);
	return (new_node);
}

int	append_node(t_data **head, char **token_arr, int *i, int (*init)(t_data *, char **, int *))
{
	t_data	*tmp;

	tmp = NULL;
	if ((*head) == NULL)
	{
		(*head) = create_node(token_arr, i, init);
		if ((*head)->next == NULL)
			return (1);
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_node(token_arr, i, init);
		if (tmp->next == NULL)
			return (1);
	}
	return (0);
}

t_data	*parser(char **token_arr)
{
	int		i;
	t_data	*head;

	head = NULL;
	i = 0;
	if (token_arr == NULL)
		return (NULL);
	while (token_arr[i] != NULL)
		append_node(&head, token_arr, &i, init_content);
	list_test(head);
	free_double(token_arr);
	return (head);
}
