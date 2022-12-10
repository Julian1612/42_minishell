/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_array_creator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:00:40 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/10 11:00:08 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	get_token_length(char *str, int *j)
{
	int	token_len;

	token_len = 0;
	while (str[*j] != '\0')
	{
		if (str[*j] == ' ')
			skip_whitespace(str, j);
		else if (str[*j] == '-')
		{
			counter_flag_len(str, j, &token_len);
			return (token_len);
		}
		else if (str[*j] == '|' || str[*j] == '<' || str[*j] == '>')
		{
			counter_opp_len(str, j, &token_len);
			return (token_len);
		}
		else if (str[*j] == '"' || str[*j] == 39)
		{
			counter_quote_len(str, j, &token_len);
			return (token_len);
		}
		else if (str[*j] >= '0' && str[*j] <= '9')
		{
			counter_nbrs_len(str, j, &token_len);
			return (token_len);
		}
		else if (str[*j] >= '!' && str[*j] <= '~')
		{
			counter_str_len(str, j, &token_len);
			return (token_len);
		}
	}
	if (str[*j] == '\0')
			return (token_len);
	else
		return (-1);
}

void counter_str_len(char *str, int *j, int *token_len)
{
	while ((str[*j] >= '!' && str[*j] <= '~') && str[*j] != '\0')
	{
		(*j)++;
		(*token_len)++;
		if (str[*j] == '"' || str[*j] == 39)
		{
			(*j)++;
			(*token_len)++;
			while (str[*j] != '"' && str[*j] != 39 && str[*j] != '\0')
			{
				// printf("str[%d] = %c\n", (*i), str[*i]);
				(*j)++;
				(*token_len)++;
			}
			(*j)++;
			(*token_len)++;
		}
	}
}

void counter_flag_len(char *str, int *j, int *token_len)
{
	(*j)++;
	(*token_len)++;
	while (((str[*j] >= 'a' && str[*j] <= 'z')
			|| (str[*j] >= 'A' && str[*j] <= 'Z'))
			&&str[*j] != '\0')
	{
		if (str[*j + 1] == '"' || str[*j + 1] == 39)
		{
			(*j) += 2;
			(*token_len) += 2;
			while (str[*j] != '"' && str[*j] != '\0')
			{
				// printf("str[%d] = %c\n", (*i), str[*i]);
				(*j)++;
				(*token_len)++;
			}
			(*j)++;
			(*token_len)++;
		}
		(*j)++;
		(*token_len)++;
	}
}

void counter_opp_len(char *str, int *j, int *token_len)
{
	if ((str[*j] == '>' && str[*j + 1] == '>') ||
		(str[*j] == '<' && str[*j + 1] == '<'))
	{
		(*j) += 2;
		(*token_len) += 2;
		return ;
	}
	(*j)++;
	(*token_len)++;
}

void counter_nbrs_len(char *str, int *i, int *token_len)
{
	(*token_len)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		(*token_len)++;
		(*i)++;
	}
	// printf("%d--skip_nbrs\n", *counter);
}


void counter_dqoutes_len(char *str, int *j, int *token_len)
{
	if (str[*j] == '"' && str[*j + 1] == '"')
	{
		(*j) += 2;
		return ;
	}
	(*token_len)++;
	(*j)++;
	while (str[*j] != '"' && str[*j] != '\0')
	{
		(*token_len)++;
		(*j)++;
	}
	if (str[*j + 1] == '"')
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
