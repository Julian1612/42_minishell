/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:47 by dgross            #+#    #+#             */
/*   Updated: 2022/11/24 15:24:58 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int ft_echo(t_koopa *shell)
{
	int n_flag;

	n_flag = False;
	if (ft_strcmp(shell->flag, "-n") == True)
		n_flag = True;
	printf("%s", shell->str);
	if (!n_flag)
		printf("\n");
	shell->exit_status = 1;
	return (0);
}
