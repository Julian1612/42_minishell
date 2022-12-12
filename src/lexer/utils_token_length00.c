/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_length00.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:37:00 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/12 09:07:09 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	counter_flag_len(char *str, int *j)
{
	int	token_len;

	token_len = 0;
	(*j)++;
	token_len++;
	while (((str[*j] >= 'a' && str[*j] <= 'z')
			|| (str[*j] >= 'A' && str[*j] <= 'Z'))
		&& str[*j] != '\0')
	{
		if (str[*j + 1] == '"' || str[*j + 1] == 39)
		{
			(*j) += 2;
			token_len += 2;
			while (str[*j] != '"' && str[*j] != '\0')
			{
				(*j)++;
				token_len++;
			}
			(*j)++;
			token_len++;
		}
		(*j)++;
		token_len++;
	}
	return (token_len);
}

int	counter_opp_len(char *str, int *j)
{
	int	token_len;

	token_len = 0;
	if ((str[*j] == '>' && str[*j + 1] == '>')
		|| (str[*j] == '<' && str[*j + 1] == '<'))
	{
		(*j) += 2;
		token_len += 2;
		return (token_len);
	}
	(*j)++;
	token_len++;
	return (token_len);
}

int	counter_quote_len(char *str, int *j)
{
	if (str[*j] == 39)
		return (counter_sqoutes_len(str, j));
	else if (str[*j] == '"')
		return (counter_dqoutes_len(str, j));
	return (0);
}
