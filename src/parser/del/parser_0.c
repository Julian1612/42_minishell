/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:src/parser/del/parser_0.c
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:24:15 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/06 20:57:28 by jschneid         ###   ########.fr       */
=======
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:24:15 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/06 19:18:05 by dgross           ###   ########.fr       */
>>>>>>> 86b5271ff4582449f23302f1054b4bd71d04c395:src/parser/parser_0.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	init_test(t_data *node, char **token_arr, int *i)
{
	(void) token_arr;
	(void) *i;
	node->cmd_name = NULL;
	node->cmd_line = NULL;
	node->operator = PIPE;
	node->next = NULL;
	return (0);
}

int	init_data(t_data *t_data, char **toke_arr)
{
	node->cmd_name = ft_strdup(token_arr[*i + 1]);
	node->cmd_line = (char **) malloc(sizeof(char *) * 2);
	if (node->cmd_line == NULL)
		return (1);
	node->cmd_line[0] = ft_strdup(token_arr[*i + 1]);
	node->cmd_line[1] = NULL;
	return (0);
}

int	init_redir(t_data *node, char **token_arr, int *i)
{
	init_data(node, token_arr);
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
<<<<<<< HEAD:src/parser/del/parser_0.c
=======
	//printf("End of init_redir token_arr[%d] = %s\n", *i, token_arr[*i]);
>>>>>>> 86b5271ff4582449f23302f1054b4bd71d04c395:src/parser/parser_0.c
	if (token_arr[*i] == NULL)
		return (0);
	if (token_arr[*i][0] == '|')
		append_node(&node, token_arr, i, init_test);
	return (0);
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

int init_cmd_line(t_data *node, char **token_arr, int *i)
{
	int	j;

	j = 0;
	while (j < num_cmd)
	{
		if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
		{
			(*i) += 2;
			continue ;
		}
		node->cmd_line[j] = ft_strdup(token_arr[*i]);
		if (node->cmd_line[j] == NULL)
			return (1);
		j++;
		(*i)++;
	}
	while (token_arr[*i] != NULL && token_arr[*i][0] != '|')
		(*i)++;
}

int	init_cmd(t_data *node, char **token_arr, int *i)
{
	int	num_cmd;

	node->next = NULL;
	node->operator = get_op(token_arr, *i);
	num_cmd = c_cmd(&node, token_arr, *i);
	node->cmd_name = ft_strdup(token_arr[*i]);
	if (node->cmd_name == NULL)
		return (1);
	node->cmd_line = (char **) malloc(sizeof(char *) * (num_cmd + 1));
	if (node->cmd_line == NULL)
		return (1);
	node->cmd_line[num_cmd] = NULL;
	init_cmd_line(node, token_arr, i);
	return (0);
}

int	handle_redir(t_data *node, char **token_arr, int *i)
{
	int	flag;

	flag = 0;
	if (token_arr[*i][0] == '<' || token_arr[*i][0] == '>')
	{
		init_redir(node, token_arr, i);
		if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
			return (0);
		while (token_arr[*i] != NULL && (token_arr[*i][0] == '<'
			|| token_arr[*i][0] == '>') && token_arr[*i][0] != '|')
			append_node(&node, token_arr, i, init_redir);
		flag = 1;
	}
	if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
		return (0);
	if (flag == 1)
		append_node(&node, token_arr, i, init_cmd);
	else
		init_cmd(node, token_arr, i);
	if (token_arr[*i] == NULL)
		return (0);
	if (token_arr[*i] == NULL || token_arr[*i][0] == '|')
		(*i)++;
	return (0);
}
