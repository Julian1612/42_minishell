/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:47 by dgross            #+#    #+#             */
/*   Updated: 2022/12/07 16:16:18 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h" // ft_stcmp
#include <stdio.h> // printf
#include <unistd.h>
#include <string.h>
// überarbeiten macht so kein sinn
int	ft_echo(char **cmd_line)
{
	int	n_flag;
	int i;

	i = 1;
	n_flag = FALSE;
	if (ft_strcmp(cmd_line[1], "-n") == TRUE)
	{
		n_flag = TRUE;
		i++;
	}
	while (cmd_line[i] != NULL)
	{
		printf("%s", cmd_line[i]);
		i++;	
		if (cmd_line[i] != NULL)
			printf(" ");
	}
	if (!n_flag)
		printf("\n");
	return (0);
}

// ft_strcmp wie die richtige umschreiben sonst geht es nicht richtig