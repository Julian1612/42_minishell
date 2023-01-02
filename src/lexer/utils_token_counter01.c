/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_counter01.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:30:55 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/02 18:31:41 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	skip_qoutes(char *str, int *i, int *counter)
{
	(*counter)++;
	while ((str[*i] == '\'' || str[*i] == '\"') && str[(*i)] != '\0')
	{
		if (str[*i] == '\'')
		{
			while (str[++(*i)] != '\0' && str[*i] != '\'')
				;
			(*i)++;
		}
		else if (str[*i] == '\"')
		{
			while (str[++(*i)] != '\0' && str[*i] != '\"')
				;
			(*i)++;
		}
		if (str[*i] >= '!' && str[*i] <= '~')
		{
			while ((str[++(*i)] != '\0' && str[*i] >= '!' && str[*i] <= '~'))
				;
		}
	}
}

void	skip_nbrs(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	if (str[*i] >= '!' && str[*i] <= '~')
	{
		while ((str[++(*i)] != '\0' && str[*i] >= '!' && str[*i] <= '~'))
			;
	}
}

void	skip_str(char *str, int *i, int *counter)
{
	(*counter)++;
	while (((str[*i] >= '!' && str[*i] <= '~')
			|| (!ft_isascii(str[*i]))) && str[*i] != '\0')
	{
		if (str[*i] == '\'')
		{
			while (str[++(*i)] != '\0' && str[*i] != '\'')
				;
			if (str[(*i)] != '\0')
				(*i)++;
		}
		else if (str[*i] == '\"')
		{
			while (str[++(*i)] != '\0' && str[*i] != '\"')
				;
			if (str[(*i)] != '\0')
				(*i)++;
		}
		else if (!ft_isascii(str[*i]))
			while (str[*i] != '\0' && !ft_isascii(str[*i]))
				(*i)++;
		else
			(*i)++;
	}
}
