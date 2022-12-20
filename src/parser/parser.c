/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:03 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/20 18:46:53 by jschneid         ###   ########.fr       */
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
		printf("\e[95moperator: %d\n", cur->operator);
		cur = cur->next;
		g++;
	}
}

int get_op(char **token_arr, int i)
{
	int	v;

	v = 0;
	i++;
	while (token_arr[i])
	{
		printf("--->%s\n", token_arr[i]);
		if (token_arr[i][0] == '|')
		{
			v = PIPE;
			break;
		}
		else if (token_arr[i][0] == '<')
		{
			v = CMD;
			break;
		}
		else if (token_arr[i][0] == '>')
		{
			v = CMD;
			break;
		}
		else if (token_arr[i] == NULL)
		{
			v = CMD;
			break;
		}
		else
			i++;
	}
	printf("%d\n", v);
	return (v);
}

int	init_node(t_data *node, char **token_arr, int *i)
{
	int	num_cmd;
	int	j;

	printf("token_arr[%d] = %s\n", *i, token_arr[*i]);
	if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
	{
		node->cmd_name = ft_strdup(token_arr[*i + 1]);
		node->cmd_line = (char **) malloc(sizeof(char *) * 2);
		if (node->cmd_line == NULL)
			return (1);
		node->cmd_line[0] = ft_strdup(token_arr[*i + 1]);
		node->cmd_line[1] = NULL;
		if (token_arr[*i][0] == '<')
			node->operator = IN;
		else if (token_arr[*i][0] == '>')
			node->operator = OUT;
		node->next = NULL;
		(*i) += 2;
	}
	else
	{
		if (token_arr[*i][0] == '|')
			(*i)++;
		node->operator = get_op(token_arr, *i);
		num_cmd = count_cmd(token_arr, *i);
		node->cmd_name = ft_strdup(token_arr[*i]);
		node->cmd_line = (char **) malloc(sizeof(char *) * num_cmd + 1);
		if (node->cmd_line == NULL)
			return (1);
		node->cmd_line[num_cmd] = NULL;
		j = 0;
		while (j < num_cmd)
		{
			node->cmd_line[j] = ft_strdup(token_arr[*i]);
			j++;
			(*i)++;
		}
		node->next = NULL;
	}
	return (0);
}

t_data	*create_node(char **token_arr, int *i)
{
	t_data	*new_node;

	new_node = (t_data *) malloc(sizeof(t_data));
	if (new_node == NULL)
		return (NULL);
	init_node(new_node, token_arr, i);
	return (new_node);
}

void	append_node(t_data **head, char **token_arr, int *i)
{
	t_data	*b;

	if ((*head) == NULL)
		(*head) = create_node(token_arr, i);
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

t_data	*parser(char **token_arr)
{
	int		i;
	t_data	*head;

	head = NULL;
	i = 0;
	if (token_arr == NULL)
		return (NULL);
	while (token_arr[i] != NULL)
	{
		append_node(&head, token_arr, &i);
		if (token_arr[i] == NULL)
			break ;
	}
	list_test(head);
	return (head);
}
