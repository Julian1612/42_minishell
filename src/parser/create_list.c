/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:07:16 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/12 14:23:18 by jschneid         ###   ########.fr       */
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
	t_data	*tmp;
	t_data	*new_node;

	head = create_head();
	i = 1;
	while (i < nbr_cmd)
	{
		new_node = (t_data *) malloc(sizeof(t_data));
		if (new_node == NULL)
		{
			perror("minishell: malloc failed\n");
			return (NULL);
		}
		init_node_null(new_node);
		tmp->next = new_node;
		tmp = new_node;
		i++;
	}
	printf("creted nodes: %d\n", i);
	return (head);
}

void	init_node_null(t_data *node)
{
	node->cmd_name = NULL;
	node->cmd_line = NULL;
	node->operator = -1;
	node->next = NULL;
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

int	count_cmd(char **token_arr, int i)
{
	int	count;

	count = 0;
	while (token_arr[i][0] != '|' && token_arr[i][0] != '\0') // anderen opperatoren einfügen >>, <<, ||
	{
		count++;
		i++;
	}
	return (count);
}

// char	**init_cmd_line(char **token_arr, int *i)
// {
// 	int	cmd_count;

// 	// cmd_count = count_cmd(token_arr, i);
// 	// printf("OG cmd_count: %d\n", cmd_count);
// 	// cmd_list->cmd_line = (char **) malloc(sizeof(char *) * cmd_count); // 100 ist nur ein Platzhalter
// 	// while (token_arr[*i] != '|' && token_arr[*i] != '\0') // anderen opperatoren einfügen >>, <<, ||
// 	// {

// 	// }
// 	return (NULL);
// }

void	init_list(t_data *head, char **token_arr)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = head;
	while (token_arr[i] != NULL)
	{
		printf("token_arr[%d]: %s\n", i, token_arr[i]);
		tmp->cmd_name = ft_strdup(token_arr[i]);
		// tmp->cmd_line = init_cmd_line(token_arr, &i);
		// tmp->operator = get_following_operator(token_arr[i]);
		// tmp = tmp->next;
		i++;
	}
}
