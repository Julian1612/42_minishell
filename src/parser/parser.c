/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:50:03 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/09 19:30:54 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	free_double(token_arr);
	return (head);
}

int	append_node(t_data **head, char **token_arr, int *i,
	int (*init)(t_data *, char **, int *))
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

t_data	*create_node(char **token_arr, int *i,
	int (*init)(t_data *, char **, int *))
{
	t_data	*new_node;

	new_node = (t_data *) malloc(sizeof(t_data));
	if (new_node == NULL)
		return (NULL);
	if (init(new_node, token_arr, i))
		return (NULL);
	return (new_node);
}

int	init_content(t_data *node, char **token_arr, int *i)
{
	int	redirection;

	redirection = redir_check(token_arr, *i);
	if (redirection > 0)
	{
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

int	redir_check(char **token_arr, int i)
{
	int	counter;

	counter = 0;
	if (token_arr[i] == NULL)
		return (-1);
	while (token_arr[i] != NULL && token_arr[i][0] != '|')
	{
		if (token_arr[i][0] == '<' || token_arr[i][0] == '>')
			counter++;
		if (token_arr[i] == NULL)
			return (counter);
		i++;
	}
	return (counter);
}
