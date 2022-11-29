/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:26 by dgross            #+#    #+#             */
/*   Updated: 2022/11/29 10:59:14 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_builtins(t_koopa *shell)
{
	if (ft_strcmp(shell->cmd_str[0], "cd"))
		ft_cd(shell);
	else if (ft_strcmp(shell->cmd, "echo"))
		ft_echo(shell);
	else if (ft_strcmp(shell->cmd, "env"))
		ft_env(shell);
	else if (ft_strcmp(shell->cmd, "exit"))
		ft_exit(shell);
	else if (ft_strcmp(shell->cmd, "export"))
		ft_export(shell);
	else if (ft_strcmp(shell->cmd, "pwd"))
		ft_pwd(shell);
	else if (ft_strcmp(shell->cmd, "unset"))
		ft_unset(shell);
	else
		print_error();
	return (0);
}
