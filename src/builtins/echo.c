/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:47 by dgross            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/08 09:38:54 by jschneid         ###   ########.fr       */
=======
/*   Updated: 2022/12/08 16:00:51 by dgross           ###   ########.fr       */
>>>>>>> 5f3c3a5b01b087a24c24f0b5b87c89c75a95cf13
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
	if (!ft_strcmp(cmd_line[i], "-n"))
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
