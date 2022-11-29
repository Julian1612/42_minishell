/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/11/29 14:19:07 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // dup access fork

int	ft_execute(t_koopa *shell, t_data *data)
{
	int	tmp_fd;

	tmp_fd = dup(STDIN_FILENO);
	ft_redirection();
	if (ft_execute_builtin(shell))
		return (0);
	else
		ft_execute_cmd(shell);
	while ()
	{
		//watiing and get exec status from builtin and or cmd
	}
}
