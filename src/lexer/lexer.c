/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:51:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/11 17:40:08 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	tokenizer(char *str)
{
	char	**token_arr;
	int		token_count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	token_count = token_counter(str);
	token_arr = (char **) malloc(sizeof(char *) * (token_count + 1));
	if (token_arr == NULL)
		return (1);
	while (i < token_count)
	{
		if (init_arr(token_arr, str, &j, &i) == 1)
			return (1);
		i++;
	}
	token_arr[token_count] = NULL;
	// Test //
	int x = 0;
	while (token_arr[x] != NULL)
	{
		printf("%s\n", token_arr[x]);
		x++;
	}
	// Test //
	return (0);
}

int	init_arr(char **token_arr, char *str, int *j, int *i)
{
	int	token_len;
	int	start_copy;

	start_copy = *j;
	token_len = get_token_length(str, j);
	if (token_len == -1)
		return (1);
	token_arr[*i] = (char *) malloc(sizeof(char) * token_len + 1);
	if (token_arr[*i] == NULL)
		return (1);
	skip_whitespace(str, &start_copy);
	cpy_token(str, token_arr[*i], token_len, start_copy);
	token_arr[*i][token_len] = '\0';
	return (0);
}

void	cpy_token(char *str, char *token_arr, int token_len, int start_copy)
{
	int	i;

	i = 0;
	while (i < token_len)
	{
		token_arr[i] = str[start_copy];
		i++;
		start_copy++;
	}
}
