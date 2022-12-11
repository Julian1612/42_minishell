/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_length03.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:00:21 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/11 18:00:23 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	counter_str_len(char *str, int *j)
{
	int	token_len;

	token_len = 0;
	while ((str[*j] >= '!' && str[*j] <= '~') && str[*j] != '\0')
	{
		(*j)++;
		token_len++;
		if (str[*j] == '"' || str[*j] == 39)
		{
			(*j)++;
			token_len++;
			while (str[*j] != '"' && str[*j] != 39 && str[*j] != '\0')
			{
				(*j)++;
				token_len++;
			}
			(*j)++;
			token_len++;
		}
	}
	return (token_len);
}
