/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:26 by dgross            #+#    #+#             */
/*   Updated: 2022/11/29 14:05:19 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_builtins(t_koopa *shell, t_data *data)
{
	if (ft_strcmp(data->cmd, "cd"))
		ft_cd(shell, data);
	else if (ft_strcmp(data->cmd, "echo"))
		ft_echo(shell, data);
	else if (ft_strcmp(data->cmd, "env"))
		ft_env(shell);
	else if (ft_strcmp(data->cmd, "exit"))
		ft_exit(shell);
	else if (ft_strcmp(data->cmd, "export"))
		ft_export(shell, data);
	else if (ft_strcmp(data->cmd, "pwd"))
		ft_pwd();
	else if (ft_strcmp(data->cmd, "unset"))
		ft_unset(shell);
	else
		print_error();
	return (0);
}
