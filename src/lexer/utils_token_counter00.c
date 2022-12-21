/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_counter00.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:47:09 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/21 14:56:49 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	skip_whitespace(char *str, int *i)
{
	while ((str[*i] == ' ' || str[*i] == '\t') && str[*i] != '\0')
		(*i)++;
}

void	skip_flags(char *str, int *i, int *counter)
{
	(*counter)++;
	(*i)++;
	while (((str[*i] >= 'a' && str[*i] <= 'z')
			|| (str[*i] >= 'A' && str[*i] <= 'Z'))
		&& str[*i] != '\0')
	{
		if (str[*i + 1] == '"' || str[*i + 1] == 39)
		{
			(*i) += 2;
			while (str[*i] != '"' && str[*i] != '\0')
				(*i)++;
			(*i)++;
		}
		(*i)++;
	}
}

void	skip_opperator(char *str, int *i, int *counter)
{
	if ((str[*i] == '>' && str[*i + 1] == '>')
		|| (str[*i] == '<' && str[*i + 1] == '<'))
	{
		(*i) += 2;
		(*counter)++;
		return ;
	}
	(*i)++;
	(*counter)++;
}

void	skip_sqoutes(char *str, int *i, int *counter)
{
	if (str[*i] == 39 && str[*i + 1] == 39)
	{
		(*i) += 2;
		return ;
	}
	(*counter)++;
	(*i)++;
	while (str[*i] != 39 && str[*i] != '\0')
		(*i)++;
	if (str[*i + 1] == 39)
	{
		(*i)++;
		return ;
	}
	if (str[*i + 1] != ' ')
	{
		while (str[*i] >= '!' && str[*i] <= '~' && str[*i] != '\0')
			(*i)++;
	}
	else
		(*i)++;
}

void	skip_dqoutes(char *str, int *i, int *counter)
{
	if (str[*i] == '"' && str[*i + 1] == '"')
	{
		(*i) += 2;
		return ;
	}
	(*counter)++;
	(*i)++;
	while (str[*i] != '"' && str[*i] != '\0')
		(*i)++;
	if (str[*i + 1] == '"')
	{
		(*i)++;
		return ;
	}
	if (str[*i + 1] != ' ')
		while (str[*i] >= '!' && str[*i] <= '~' && str[*i] != '\0')
			(*i)++;
	else
		(*i)++;
}
