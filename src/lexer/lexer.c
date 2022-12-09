/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:51:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/09 17:32:45 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tokenizer(char *str)
{
	char	**token_arr;
	int		token_count;
	int		token_len;
	int		i;
	int		j;
	int		start_copy;

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
	token_arr[token_count] = NULL;
	// // Test ///
	i = 0;
	while (token_arr[i] != NULL)
	{
		printf("token_arr[%d] = %s\n", i, token_arr[i]);
		i++;
	}
	// // Test ///
	return (0);
}
