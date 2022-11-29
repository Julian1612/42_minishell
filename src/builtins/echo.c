/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:47 by dgross            #+#    #+#             */
/*   Updated: 2022/11/29 13:56:07 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h" // ft_stcmp
#include <stdio.h> // printf

int	ft_echo(t_koopa *shell, t_data *data)
{
	int	n_flag;

	n_flag = FALSE;
	if (ft_strcmp(data->flag, "-n") == TRUE)
		n_flag = TRUE;
	printf("%s", data->arg);
	if (!n_flag)
		printf("\n");
	shell->exit_status = 1;
	return (0);
}
