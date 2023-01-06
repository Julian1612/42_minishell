/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:40:03 by dgross            #+#    #+#             */
/*   Updated: 2023/01/06 10:19:40 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/wait.h> // waitpid

void	get_exit_status(t_koopa *shell)
{
	while (waitpid(0, &g_exit_status, 0) > 0)
		g_exit_status = WEXITSTATUS(g_exit_status);
	if (shell->exit == BUILTIN)
		g_exit_status = shell->exit_code;
	if (shell->skip == 1)
		g_exit_status = 1;
	shell->skip = 0;
}
