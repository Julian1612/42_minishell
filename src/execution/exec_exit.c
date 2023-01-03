/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:40:03 by dgross            #+#    #+#             */
/*   Updated: 2023/01/03 11:03:10 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h> // waitpid

void	get_exit_status(t_koopa *shell)
{
	while (waitpid(0, &shell->exit_status, 0) > 0)
		shell->exit_status = WEXITSTATUS(shell->exit_status);
	if (shell->skip == 1)
		shell->exit_status = 1;
}
