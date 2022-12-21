/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:47 by dgross            #+#    #+#             */
/*   Updated: 2022/12/20 20:16:40 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h" // ft_stcmp
#include <stdio.h> // printf
#include <unistd.h>
#include <string.h>

static int	check_for_n(char *cmd_line)
{
	int	i;

	i = 1;
	if (cmd_line)
	{
		if (ft_strncmp(cmd_line, "-n", 2) == 0)
		{
			while (cmd_line[i] == 'n')
				i++;
			if (cmd_line[i] == '\0')
				return (0);
		}
	}
	return (1);
}

int	ft_echo(char **cmd_line)
{
	int	n_flag;
	int	i;

	i = 1;
	n_flag = FALSE;
	while (check_for_n(cmd_line[i]) == 0)
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
	if (n_flag == -1)
		printf("\n");
	return (0);
}
