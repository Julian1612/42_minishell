/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_create_list00.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:16:29 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/20 17:01:45 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	count_cmd(char **token_arr, int i)
{
	int	count;

	count = 0;
	while (token_arr[i] != NULL) // anderen opperatoren einfügen >>, <<, ||
	{
		if (token_arr[i][0] == '|' || token_arr[i][0] == '>'
			|| token_arr[i][0] == '<' || token_arr[i][0] == '\0')
			break ;
		count++;
		i++;
	}
	return (count);
}
