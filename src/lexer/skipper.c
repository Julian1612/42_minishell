/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Skipper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:30:55 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/03 11:51:14 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	skip_qoutes(char *str, int *i, int *counter)
{
	char	typ;

	(*counter)++;
	typ = 'X';
	while ((str[*i] == '\'' || str[*i] == '\"') && str[(*i)] != '\0')
	{
		if (str[*i] == '\'' || str[*i] == '\"')
		{
			typ = str[*i];
			while (str[++(*i)] != '\0' && str[*i] != typ)
				;
			if (str[(*i)] != '\0')
				(*i)++;
		}
		if (!ft_isspace(str[*i]))
			while (!ft_isspace(str[*i]))
				(*i)++;
	}
}

void	skip_nbrs(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	if (!ft_check_after(str[*i]))
		while (!ft_check_after(str[*i]))
			(*i)++;
}

void	skip_str(char *str, int *i, int *counter)
{
	char	typ;

	(*counter)++;
	typ = 'X';
	while (((str[*i] >= '!' && str[*i] <= '~')
			|| (!ft_isascii(str[*i]))) && str[*i] != '\0')
	{
		if (str[*i] == '\'' || str[*i] == '\"')
		{
			typ = str[*i];
			while (str[++(*i)] != '\0' && str[*i] != typ)
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
