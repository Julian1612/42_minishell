/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:07:16 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/15 16:17:35 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_data	*create_list(const int nbr_cmd)
{
	int		i;
	t_data	*head;
	t_data	*new_node;

	head = create_head();
	i = 1;
	while (i < nbr_cmd)
	{
		new_node = malloc(sizeof(t_data));
		init_node_null(new_node);
		new_node->next = head;
		head = new_node;
		i++;
	}
	return (head);
}

t_data	*create_head(void)
{
	t_data	*head;

	head = (t_data *) malloc(sizeof(t_data));
	if (head == NULL)
	{
		perror("minishell: malloc failed\n");
		return (NULL);
	}
	init_node_null(head);
	return (head);
}

char	**init_cmd_line(char **token_arr, int *i)
{
	char	**arr;
	int		cmd_count;
	int		j;

	cmd_count = count_cmd(token_arr, *i);
	arr = (char **) malloc(sizeof(char *) * (cmd_count + 1)); // 100 ist nur ein Platzhalter
	if (arr == NULL)
		return (NULL);
	j = 0;
	while (j < cmd_count)
	{
		arr[j] = ft_strdup(token_arr[*i]);
		j++;
		(*i)++;
	}
	arr[j] = NULL;
	return (arr);
}

int	get_following_operator(char **token_arr, int i)
{
	while (token_arr[i] != NULL) // anderen opperatoren einfügen >>, <<, ||
	{
		if (token_arr[i][0] == '|')
			return (PIPE);
		i++;
	}
	return (-1);
}

void	init_list(t_data *head, char **token_arr)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = head;
	while (token_arr[i] != NULL && tmp != NULL)
	{
		tmp->cmd_name = ft_strdup(token_arr[i]);
		tmp->cmd_line = init_cmd_line(token_arr, &i);
		tmp->operator = get_following_operator(token_arr, i);
		tmp = tmp->next;
		i++;
	}
}
