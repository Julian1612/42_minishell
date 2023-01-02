/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_length01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:38:30 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/02 18:32:33 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	skip_sqoute(char *str, int *j, int *token_len)
{
	while (str[*j] != 39 && str[*j] != '\0')
	{
		(*token_len)++;
		(*j)++;
	}
}

void	skip_dqoute(char *str, int *j, int *token_len)
{
	while ((str[*j] != '"' && str[*j]) != '\0')
	{
		(*token_len)++;
		(*j)++;
	}
}

void	skip_char(char *str, int *j, int *token_len)
{
	while (str[*j] >= '!' && str[*j] <= '~' && str[*j] != '\0')
	{
		(*token_len)++;
		(*j)++;
	}
}

int	counter_dqoutes_len(char *str, int *j)
{
	int	token_len;

	token_len = 0;
	if (str[*j] == '"' && str[*j + 1] == '"')
	{
		(*j) += 2;
		return (token_len);
	}
	token_len++;
	(*j)++;
	skip_dqoute(str, j, &token_len);
	if (str[*j + 1] == '"')
	{
		token_len++;
		(*j)++;
		return (token_len);
	}
	if (str[*j + 1] != ' ')
		skip_char(str, j, &token_len);
	else
	{
		token_len++;
		(*j)++;
	}
	return (token_len);
}

int	counter_sqoutes_len(char *str, int *j)
{
	int	token_len;

	token_len = 0;
	if (str[*j] == 39 && str[*j + 1] == 39)
	{
		(*j) += 2;
		return (token_len);
	}
	token_len++;
	(*j)++;
	skip_sqoute(str, j, &token_len);
	if (str[*j + 1] == 39)
	{
		token_len++;
		(*j)++;
		return (token_len);
	}
	if (str[*j + 1] != ' ')
		skip_char(str, j, &token_len);
	else
	{
		token_len++;
		(*j)++;
	}
	return (token_len);
}

int	counter_nbrs_len(char *str, int *i)
{
	int	token_len;

	token_len = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		token_len++;
		(*i)++;
	}
	if (str[*i] >= '!' && str[*i] <= '~')
	{
		while ((str[(*i)] != '\0' && str[*i] >= '!' && str[*i] <= '~'))
		{
			token_len++;
			(*i)++;
		}
	}
	return (token_len);
}
