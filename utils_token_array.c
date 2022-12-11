/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:04:14 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/11 17:57:17 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// void	cpy_token(char *str, char *token_arr, int token_len, int start_copy)
// {
// 	int	i;

// 	i = 0;
// 	while (i < token_len)
// 	{
// 		token_arr[i] = str[start_copy];
// 		i++;
// 		start_copy++;
// 	}
// }

// c

// int	counter_dqoutes_len(char *str, int *j)
// {
// 	int	token_len;

// 	token_len = 0;
// 	if (str[*j] == '"' && str[*j + 1] == '"')
// 	{
// 		(*j) += 2;
// 		return (token_len);
// 	}
// 	token_len++;
// 	(*j)++;
// 	skip_qoute(str, j, &token_len);
// 	if (str[*j + 1] == '"')
// 	{
// 		token_len++;
// 		(*j)++;
// 		return (token_len);
// 	}
// 	if (str[*j + 1] != ' ')
// 		skip_char(str, j, &token_len);
// 	else
// 	{
// 		token_len++;
// 		(*j)++;
// 	}
// 	return (token_len);
// }

// int	counter_sqoutes_len(char *str, int *j)
// {
// 	int	token_len;

// 	token_len = 0;
// 	if (str[*j] == 39 && str[*j + 1] == 39)
// 	{
// 		(*j) += 2;
// 		return (token_len);
// 	}
// 	token_len++;
// 	(*j)++;
// 	skip_qoute(str, j, &token_len);
// 	if (str[*j + 1] == 39)
// 	{
// 		token_len++;
// 		(*j)++;
// 		return (token_len);
// 	}
// 	if (str[*j + 1] != ' ')
// 		skip_char(str, j, &token_len);
// 	else
// 	{
// 		token_len++;
// 		(*j)++;
// 	}
// 	return (token_len);
// }

// int	counter_quote_len(char *str, int *j)
// {
// 	if (str[*j] == 39)
// 		return (counter_sqoutes_len(str, j));
// 	else if (str[*j] == '"')
// 		return (counter_dqoutes_len(str, j));
// 	return (0);
// }
