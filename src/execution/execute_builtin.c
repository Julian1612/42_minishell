/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:26 by dgross            #+#    #+#             */
/*   Updated: 2022/11/30 14:52:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_builtins(t_koopa *shell, t_data *data)
{
	if (ft_strcmp(data->cmd_name, "cd"))
		shell->exit_status = ft_cd(shell, data->cmd_line[1]);
	else if (ft_strcmp(data->cmd_name, "echo"))
		shell->exit_status = ft_echo(shell, data->cmd_line);
	else if (ft_strcmp(data->cmd_name, "env"))
		shell->exit_status = ft_env(shell);
	else if (ft_strcmp(data->cmd_name, "exit"))
		ft_exit(shell);
	else if (ft_strcmp(data->cmd_name, "export"))
		shell->exit_status = ft_export(shell, data->cmd_line[1]);
	else if (ft_strcmp(data->cmd_name, "pwd"))
		shell->exit_status = ft_pwd();
	else if (ft_strcmp(data->cmd_name, "unset"))
		shell->exit_status = ft_unset(shell, data->cmd_line[1]);
	else
	{
		print_error();
		shell->exit_status = 1;
	}
}
