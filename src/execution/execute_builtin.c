/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:26 by dgross            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/08 09:38:50 by jschneid         ###   ########.fr       */
=======
/*   Updated: 2022/12/08 16:00:40 by dgross           ###   ########.fr       */
>>>>>>> 5f3c3a5b01b087a24c24f0b5b87c89c75a95cf13
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>

int	ft_execute_builtin(t_koopa *shell, t_data *data)
{
	if (!ft_strcmp(data->cmd_name, "cd"))
		shell->exit_status = ft_cd(shell, data->cmd_line[1]);
	else if (!ft_strcmp(data->cmd_name, "echo"))
		shell->exit_status = ft_echo(data->cmd_line);
	else if (!ft_strcmp(data->cmd_name, "env"))
		shell->exit_status = ft_env(shell);
	else if (!ft_strcmp(data->cmd_name, "exit"))
		ft_exit(shell);
	else if (!ft_strcmp(data->cmd_name, "export"))
		shell->exit_status = ft_export(shell, data->cmd_line[1]);
	else if (!ft_strcmp(data->cmd_name, "pwd"))
		shell->exit_status = ft_pwd();
	else if (!ft_strcmp(data->cmd_name, "unset"))
		shell->exit_status = ft_unset(shell, data->cmd_line[1]);
	else
		return (1);
	return (0);
}
