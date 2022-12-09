/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_counter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:47:09 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/09 17:29:53 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void skip_str(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '!' && str[*i] <= '~' && str[*i] != '\0')
		(*i)++;
	// printf("%d--skip_str\n", *counter);
}

void skip_whitespace(char *str, int *i)
{
 	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	// printf("skip_whitespace\n");
}

void skip_nbrs(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	// printf("%d--skip_nbrs\n", *counter);
}

static void skip_sqoutes(char *str, int *i, int *counter)
{
	if (str[*i] == 39 && str[*i + 1] == 39)
	{
		// printf("%d--skip_sqoutes\n", *counter);
		(*i) += 2;
		return ;
	}
	(*counter)++;
	(*i)++;
	while (str[*i] != 39 && str[*i] != '\0')
	{
		// printf("str[%d] = %c\n", (*i), str[*i]);
		(*i)++;
	}
	// printf("str[%d] = %c\n", (*i), str[*i]);
	if (str[*i + 1] == 39)
	{
		(*i)++;
		// printf("%d--skip_sqoutes\n", *counter);
		return ;
	}
	if (str[*i + 1] != ' ')
	{
		while (str[*i] >= '!' && str[*i] <= '~' && str[*i] != '\0')
		(*i)++;
	}
	else
		(*i)++;
	// printf("%d--skip_sqoutes\n", *counter);
}

static void skip_dqoutes(char *str, int *i, int *counter)
{
	if (str[*i] == '"' && str[*i + 1] == '"')
	{
		// printf("%d--skip_sqoutes\n", *counter);
		(*i) += 2;
		return ;
	}
	(*counter)++;
	(*i)++;
	while (str[*i] != '"' && str[*i] != '\0')
	{
		// printf("str[%d] = %c\n", (*i), str[*i]);
		(*i)++;
	}
	// printf("str[%d] = %c\n", (*i), str[*i]);
	if (str[*i + 1] == '"')
	{
		(*i)++;
		// printf("%d--skip_sqoutes\n", *counter);
		return ;
	}
	if (str[*i + 1] != ' ')
		while (str[*i] >= '!' && str[*i] <= '~' && str[*i] != '\0')
		(*i)++;
	else
		(*i)++;
	// printf("%d--skip_dqoutes\n", *counter);
}

void skip_qoutes(char *str, int *i, int *counter)
{
	if (str[*i] == 39)
		skip_sqoutes(str, i, counter);
	else if (str[*i] == '"')
		skip_dqoutes(str, i, counter);
}
