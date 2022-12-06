/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:47 by dgross            #+#    #+#             */
/*   Updated: 2022/12/06 16:10:27 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h" // ft_stcmp
#include <stdio.h> // printf
#include <unistd.h>
// überarbeiten macht so kein sinn
int	ft_echo(char **cmd_line, int fd)
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
		write(fd, cmd_line[i], ft_strlen(cmd_line[i]));
		i++;	
		if (cmd_line[i] != NULL)
			write(fd, " ", 1);
	}
	if (!n_flag)
		printf("\n");
	return (0);
}
