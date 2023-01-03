/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:37:00 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/03 11:50:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	opp_len_counter(char *str, int *j)
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

int	quote_len_counter(char *str, int *j)
{
	int	token_len;

	token_len = *j;
	while (str[(*j)] != '\0' && (str[*j] == '\'' || str[*j] == '\"'))
	{
		if (str[*j] == '\'')
		{
			while (str[++(*j)] != '\0' && str[*j] != '\'')
				;
			(*j)++;
		}
		else if (str[*j] == '\"')
		{
			while (str[++(*j)] != '\0' && str[*j] != '\"')
				;
			(*j)++;
		}
		if (!ft_isspace(str[*j]))
			while (!ft_isspace(str[*j]))
				(*j)++;
	}
	token_len = *j - token_len;
	return (token_len);
}

int	str_len_counter(char *str, int *j)
{
	int		token_len;
	char	typ;

	token_len = *j;
	typ = 'X';
	while (((str[*j] >= '!' && str[*j] <= '~')
			|| (!ft_isascii(str[*j]))) && str[*j] != '\0')
	{
		if (str[*j] == '\'' || str[*j] == '\"')
		{
			typ = str[*j];
			while (str[++(*j)] != '\0' && str[*j] != typ)
				;
			if (str[(*j)] != '\0')
				(*j)++;
		}
		else if (!ft_isascii(str[*j]))
			while (str[*j] != '\0' && !ft_isascii(str[*j]))
				(*j)++;
		else
			(*j)++;
	}
	token_len = *j - token_len;
	return (token_len);
}

int	nbr_len_counter(char *str, int *i)
{
	int	token_len;

	token_len = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		token_len++;
		(*i)++;
	}
	if (!ft_check_after(str[*i]))
	{
		while (!ft_check_after(str[*i]))
		{
			token_len++;
			(*i)++;
		}
	}
	return (token_len);
}
