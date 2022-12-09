/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:04:14 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/09 17:29:23 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void	counter_sqoutes_len(char *str, int *j, int *token_len)
{
	if (str[*j] == 39 && str[*j + 1] == 39)
	{
		(*j) += 2;
		return ;
	}
	(*token_len)++;
	(*j)++;
	while (str[*j] != 39 && str[*j] != '\0')
	{
		(*token_len)++;
		(*j)++;
	}
	if (str[*j + 1] == 39)
	{
		(*token_len)++;
		(*j)++;
		return ;
	}
	if (str[*j + 1] != ' ')
	{
		while (str[*j] >= '!' && str[*j] <= '~' && str[*j] != '\0')
		{
			(*token_len)++;
			(*j)++;
		}
	}
	else
	{
		(*token_len)++;
		(*j)++;
	}
}

void	counter_quote_len(char *str, int *j, int *token_len)
{
	if (str[*j] == 39)
		counter_sqoutes_len(str, j, token_len);
	else if (str[*j] == '"')
		counter_dqoutes_len(str, j, token_len);
}
