/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:26 by dgross            #+#    #+#             */
/*   Updated: 2022/11/26 12:20:21 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_execute_builtins(t_koopa *shell)
{
	//wahrscheinlich hier auch dupen aber mal gucken vllt machen wir das in redirect aber glaube nicht
	if (ft_strcmp(shell->cmd, "cd"))
		ft_cd();
	else if (ft_strcmp(shell->cmd, "echo"))
		ft_echo();
	else if (ft_strcmp(shell->cmd, "env"))
		ft_env();
	else if (ft_strcmp(shell->cmd, "exit"))
		ft_exit();
	else if (ft_strcmp(shell->cmd, "export"))
		ft_export();
	else if (ft_strcmp(shell->cmd, "pwd"))
		ft_pwd();
	else if (ft_strcmp(shell->cmd, "unset"))
		ft_unset();	
}