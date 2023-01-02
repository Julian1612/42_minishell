/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:47:38 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/02 12:09:57 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	token_counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
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
