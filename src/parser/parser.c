/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:03 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/19 18:52:11 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void list_test(t_data *cmd_list)
{
	t_data	*cur;
	cur = cmd_list;
	// int g = 1;
	// int y = 0;

	while (cur != NULL)
	{
		// printf("%d. node: %s\n", g, cur->cmd_name);
		// printf("cmd: %s\n", cur->cmd_name);
		// while (cur->cmd_line[y] != NULL)
		// {
		// 	printf("%d.%d. cmd_line: %s\n", g, y, cur->cmd_line[y]);
		// 	y++;
		// }
		// y = 0;
		printf("operator: %d\n", cur->operator);
		cur = cur->next;
		// g++;
		printf("----------------------\n");
	}
	if (cmd_list == NULL)
		printf("kekw\n");
}

int	init_node(t_data *node, char **token_arr, int *i)
{
	node->cmd_name = NULL;
	node->cmd_line = NULL;
	node->operator = 99;
	node->next = NULL;
	(void) token_arr;
	(void) i;
	printf("hiOGGGG\n");
	return (0);
	// int	num_cmd;
	// int	j;

	// // printf("i = %d\n", *i);
	// if (token_arr[*i][0] == '<'
	// || token_arr[*i][0] == '>')
	// {
	// 	node->cmd_name = token_arr[*i + 1];
	// 	node->cmd_line = &token_arr[*i + 1];
	// 	if (token_arr[*i][0] == '<')
	// 		node->operator = IN;
	// 	else if (token_arr[*i][0] == '>')
	// 		node->operator = OUT;
	// 	(*i)++;
	// }
	// else
	// {
	// 	num_cmd = count_cmd(token_arr, *i);
	// 	node->cmd_name = ft_strdup(token_arr[*i]);
	// 	node->cmd_line = (char **)
	// 		malloc(sizeof(char *) * num_cmd + 1);
	// 	if (node->cmd_line == NULL)
	// 		return (1);
	// 	node->cmd_line[num_cmd] = NULL;
	// 	j = 0;
	// 	// printf("%d/%d\n", j, num_cmd);
	// 	while (j < num_cmd)
	// 	{
	// 		// printf("token_arr[%d] = %s\n", *i, node->cmd_name);
	// 		node->cmd_line[j] = ft_strdup(token_arr[*i]);
	// 		j++;
	// 		(*i)++;
	// 	}
	// 	node->operator = -1;
	// 	node->next = NULL;
	// }
	// return (0);
}

t_data	*create_node(char **token_arr, int *i)
{
	(void) i;
	(void) token_arr;
	t_data	*new_node;

	new_node = (t_data *) malloc(sizeof(t_data));
	if (new_node == NULL)
		return (NULL);
	new_node->cmd_name = NULL;
	new_node->cmd_line = NULL;
	new_node->operator = 99;
	new_node->next = NULL;
	// init_node(new_node, token_arr, i);
	return (new_node);
}

void	append_node(t_data **head, char **token_arr, int *i)
{
	t_data	*b;
	if ((*head) == NULL)
	{
		(*head) = create_node(token_arr, i);
	}
	else
	{
		b = *head;
		while (b->next != NULL)
		{
			b = b->next;
		}
		b->next = create_node(token_arr, i);
	}
}

// static void	add_back(t_data **lst, t_data *list)
// {
// 	t_data	*b;
// 	b = NULL;
// 	if (*lst == NULL)
// 	{
// 		printf("soos\n");
// 		*lst = list;
// 	}
// 	else
// 	{
// 		b = lastnode(*lst);
// 		b->next = list;
// 	}
// }

// static t_data	*lastnode(t_data *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }

t_data	*parser(char **token_arr)
{
	int		i;
	t_data	*head;

	head = NULL;
	i = 0;
	if (token_arr == NULL)
		return (NULL);
	// while (token_arr[i] != NULL)
	int j = 0;
	while (j < 5)
	{
		append_node(&head, token_arr, &i);
		j++;
	}
	list_test(head);
	return (head);
}

// int	cmd_counter(char **token_arr)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 1;
// 	while (token_arr[i] != NULL)
// 	{
// 		if (strcmp(token_arr[i], "|") == 0)
// 			count++;
// 		else if (strcmp(token_arr[i], ">") == 0)
// 			count++;
// 		else if (strcmp(token_arr[i], "<") == 0)
// 			count++;
// 		else if (strcmp(token_arr[i], ">>") == 0)
// 			count++;
// 		else if (strcmp(token_arr[i], "<<") == 0)
// 			count++;
// 		else if (strcmp(token_arr[i], ";") == 0)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }
