/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:00:40 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/11 17:59:16 by jschneid         ###   ########.fr       */
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
		if (str[*j] == ' ')
			skip_whitespace(str, j);
		if (str[*j] == '-')
			return (counter_flag_len(str, j));
		else if (str[*j] == '|' || str[*j] == '<' || str[*j] == '>')
			return (counter_opp_len(str, j));
		else if (str[*j] == '"' || str[*j] == 39)
			return (counter_quote_len(str, j));
		else if (str[*j] >= '0' && str[*j] <= '9')
			return (counter_nbrs_len(str, j));
		else if (str[*j] >= '!' && str[*j] <= '~')
			return (counter_str_len(str, j));
	}
	if (str[*j] == '\0')
		return (token_len);
	else
		return (-1);
}
