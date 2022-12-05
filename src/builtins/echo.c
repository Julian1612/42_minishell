/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:47 by dgross            #+#    #+#             */
/*   Updated: 2022/12/03 13:46:46 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h" // ft_stcmp
#include <stdio.h> // printf

// überarbeiten macht so kein sinn
int	ft_echo(char **cmd_line)
{
	int	n_flag;

	n_flag = FALSE;
	if (ft_strcmp(cmd_line[1], "-n") == TRUE)
		n_flag = TRUE;
	printf("%s", cmd_line[1]);
	if (!n_flag)
		printf("\n");
	return (0);
}
