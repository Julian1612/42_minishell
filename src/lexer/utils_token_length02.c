/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_length02.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:00:21 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/02 18:27:09 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	counter_str_len(char *str, int *j)
{
	int	token_len;

	token_len = *j;
	while (((str[*j] >= '!' && str[*j] <= '~')
			|| (!ft_isascii(str[*j]))) && str[*j] != '\0')
	{
		if (str[*j] == '\'')
		{
			while (str[++(*j)] != '\0' && str[*j] != '\'')
				;
			if (str[(*j)] != '\0')
				(*j)++;
		}
		else if (str[*j] == '\"')
		{
			while (str[++(*j)] != '\0' && str[*j] != '\"')
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
