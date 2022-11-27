/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/11/26 15:29:01 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // dup access fork

// main function die für die executio von cmd und builtins zuständig ist
// hier wird dann auch der exec_status abgefangen und ausgegeben nach execution
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
