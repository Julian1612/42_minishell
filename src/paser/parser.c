/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:03 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/11 11:52:39 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

t_data	*create_list(const int nbr_cmd)
{
	int		i;
	t_data	*head;
	t_data	*tmp;
	t_data	*new_node;

	head = (t_data *) malloc(sizeof(t_data));
	if (head == NULL)
	{
		perror("minishell: malloc failed\n");
		return (NULL);
	}
	head->cmd_name = NULL;
	head->cmd_line = NULL;
	head->operator = -1;
	head->next = NULL;
	tmp = head;
	i = 1;
	while (i < nbr_cmd)
	{
		new_node = (t_data *) malloc(sizeof(t_data));
		if (new_node == NULL)
		{
			perror("minishell: malloc failed\n");
			return (NULL);
		}
		new_node->cmd_name = NULL;
		new_node->cmd_line = NULL;
		new_node->operator = -1;
		new_node->next = NULL;
		tmp->next = new_node;
		tmp = new_node;
		i++;
	}
	return (head);
}

void	init_list(t_data *head, char **token_arr)
{
	int		i;
	int		j;
	t_data	*tmp;

	i = 0;
	j = 0;
	tmp = head;
	// while (token_arr[i] != NULL)
	// {

	// }
}

void	parser(char **token_arr)
{
	t_data	*head;
	int		cmd;

	cmd = cmd_counter(token_arr);
	head = create_list(cmd);
	init_list(head, token_arr);
	// TESTER //
	t_data	*cur = head;
	int f = 0;
	while (cur != NULL)
	{
		printf("%s\n", cur->cmd_name);
		while (cur->cmd_line != NULL)
		{
			printf("%s\n", cur->cmd_line);
			cur->cmd_line[f++];
		}
		f = 0;
		printf("%d\n", cur->operator);
		cur = cur->next;
	}
	// TESTER //
}
