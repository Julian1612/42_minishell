/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:47:38 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/10 11:00:40 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
		(*counter) ++;
		return ;
	}
	(*i)++;
	(*counter)++;
}

// Qoutes in einer funktion zusammen fassen
int	token_counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			skip_whitespace(str, &i);
		else if (str[i] == '-')
			skip_flags(str, &i, &count);
		else if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			skip_opperator(str, &i, &count);
		else if (str[i] == 39 || str[i] == '"')
			skip_qoutes(str, &i, &count);
		else if (str[i] >= '0' && str[i] <= '9')
			skip_nbrs(str, &i, &count);
		else if (str[i] >= '!' && str[i] <= '~')
			skip_str(str, &i, &count);
	}
	return (count);
}
