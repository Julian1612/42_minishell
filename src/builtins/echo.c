/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:47 by dgross            #+#    #+#             */
/*   Updated: 2022/11/30 12:09:01 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h" // ft_stcmp
#include <stdio.h> // printf

int	ft_echo(t_koopa *shell, char **cmd_line)
{
	int	n_flag;

	n_flag = FALSE;
	if (ft_strcmp(cmd_line[1], "-n") == TRUE)
		n_flag = TRUE;
	printf("%s", cmd_line[2]);
	if (!n_flag)
		printf("\n");
	return (0);
}
