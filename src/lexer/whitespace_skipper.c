/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token_counter00.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:47:09 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/03 11:29:52 by dgross           ###   ########.fr       */
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
	|| c == '\0');
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
