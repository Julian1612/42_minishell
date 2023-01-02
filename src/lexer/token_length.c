/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:00:40 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/02 16:24:21 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	get_token_length(char *str, int *j)
{
	int	token_len;

	token_len = 0;
	while (str[*j] != '\0')
	{
		if (str[*j] == ' ' || str[*j] == '\t')
			skip_whitespace(str, j);
		else if (str[*j] == '|' || str[*j] == '<' || str[*j] == '>')
			return (counter_opp_len(str, j));
		else if (str[*j] == '\"' || str[*j] == '\'')
			return (counter_quote_len(str, j));
		else if (str[*j] >= '0' && str[*j] <= '9')
			return (counter_nbrs_len(str, j));
		else if ((str[*j] >= '!' && str[*j] <= '~') || (!ft_isascii(str[*j])))
			return (counter_str_len(str, j));
	}
	if (str[*j] == '\0')
		return (token_len);
	else
		return (-1);
}
