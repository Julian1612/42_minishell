/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:24:09 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/09 19:18:21 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	c_cmd(t_data **node, char **token_arr, int i)
{
	int	count;

	count = 0;
	while (token_arr[i] != NULL)
	{
		if (token_arr[i][0] == '>' || token_arr[i][0] == '<')
		{
			append_redir(node, token_arr, &i, init_redir);
			continue ;
		}
		if (token_arr[i] == NULL || token_arr[i][0] == '|')
			return (count);
		count++;
		i++;
	}
	return (count);
}

int	append_redir(t_data **head, char **token_arr,
	int *i, int (*init)(t_data *, char **, int *))
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

int	init_redir(t_data *node, char **token_arr, int *i)
{
	init_data(node, token_arr, i);
	node->redir = get_pipe_nbr(token_arr, *i);
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
	return (0);
}
