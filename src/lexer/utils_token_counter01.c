/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_counter01.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:30:55 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/29 16:39:46 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	skip_qoutes(char *str, int *i, int *counter)
{
	if (str[*i] == 39)
		skip_sqoutes(str, i, counter);
	else if (str[*i] == '"')
		skip_dqoutes(str, i, counter);
}

void	skip_nbrs(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
}

void	skip_str(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '!' && str[*i] <= '~' && str[*i] != '\0')
	{
		if (str[*i] == '"' || str[*i] == 39)
		{
			(*i)++;
			while (str[*i] != '"' && str[*i] != 39 && str[*i] != '\0')
				(*i)++;
			if (str[*i + 1] == '\0')
			{
				(*i)++;
				break ;
			}
			(*i)++;
		}
		(*i)++;
	}
}
