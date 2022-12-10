/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:51:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/10 14:38:25 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmd_counter(char **token_arr)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (token_arr[i] != NULL)
	{
		printf("token_arr[%d] = %s\n", i, token_arr[i]);
		if (strcmp(token_arr[i], "|") == 0)
		{
			printf("%d | found\n", count);
			count++;
		}
		else if (strcmp(token_arr[i], ">") == 0)
		{
			printf("%d > found\n", count);
			count++;
		}
		else if (strcmp(token_arr[i], "<") == 0)
		{
			printf("%d < found\n", count);
			count++;
		}
		else if (strcmp(token_arr[i], ">>") == 0)
		{
			printf("%d >> found\n", count);
			count++;
		}
		else if (strcmp(token_arr[i], "<<") == 0)
		{
			printf("%d << found\n", count);
			count++;
		}
		else if (strcmp(token_arr[i], ";") == 0)
		{
			printf("%d ; found\n", count);
			count++;
		}
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
	head->operator = 0;
	head->next = NULL;
	tmp = head;
	i = 0;
	while (i < nbr_cmd)
	{
		new_node = (t_data *) malloc(sizeof(t_data));
		if (new_node == NULL)
		{
			perror("minishell: malloc failed\n");
			return (NULL);
		}
		new_node->cmd_name = "test";
		new_node->cmd_line = NULL;
		new_node->operator = 123;
		new_node->next = NULL;
		tmp->next = new_node;
		tmp = new_node;
		i++;
	}
	return (head);
}

int	tokenizer(char *str)
{
	char	**token_arr;
	int		token_count;
	int		token_len;
	int		i;
	int		j;
	int		start_copy;
	int 	cmd;

	token_count = token_counter(str);
	token_arr = (char **) malloc(sizeof(char *) * (token_count + 1));
	if (token_arr == NULL)
	{
		perror("minishell: malloc failed\n");
		return (1);
	}
	i = 0;
	j = 0;
	while (i < token_count)
	{
		start_copy = j;
		token_len = get_token_length(str, &j);
		if (token_len == -1)
		{
			return (1);
		}
		token_arr[i] = (char *) malloc(sizeof(char) * token_len + 1);
		if (token_arr[i] == NULL)
		{
			perror("minishell: malloc failed\n");
			return (1);
		}
		skip_whitespace(str, &start_copy);
		cpy_token(str, token_arr[i], token_len, start_copy);
		token_arr[i][token_len] = '\0';
		i++;
	}
	cmd = cmd_counter(token_arr);
	printf("cmd = %d\n", cmd);
	t_data	*head;
	head = create_list(cmd);
	t_data *cur = head;
	while (cur != NULL)
	{
		printf("%s\n", cur->cmd_name);
		// printf("%s\n", cur->cmd_line);
		printf("%d\n", cur->operator);
		cur = cur->next;
	}
	token_arr[token_count] = NULL;
	return (0);
}
