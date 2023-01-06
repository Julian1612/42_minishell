/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespace_skipper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:47:09 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/06 10:45:04 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	skip_whitespace(char *str, int *i)
{
	while ((str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
			|| str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f')
		&& str[*i] != '\0')
		(*i)++;
}

int	ft_check_after(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' \
	|| c == '\t' || c == '\v' || c == ' '\
	|| c == '\0' || c == '<' || c == '>' || c == '|' );
}

void	skip_opperator(char *str, int *i, int *countern)
{
	char	typ;

	typ = 'X';
	(*countern)++;
	if (str[*i] == '>' || str[*i] == '<')
	{
		typ = str[*i];
		while (str[++(*i)] != '\0' && str[*i] == typ)
			;
	}
	else if (str[*i] == '|')
	{
		while (str[++(*i)] != '\0' && str[*i] == '|')
			;
	}
}
