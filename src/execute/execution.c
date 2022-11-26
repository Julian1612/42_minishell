/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/11/26 12:18:44 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // dup access fork

int	ft_execute(t_koopa *shell)
{
	int tmp_fd;

	tmp_fd = dup(STDIN_FILENO);
	ft_redirection();
	if (/*check if cmd is a builtin*/)
		ft_execute_builtin(shell);
	else
		ft_execute_cmd(shell);
	//watiing and get exec status from builtin and or cmd
}
