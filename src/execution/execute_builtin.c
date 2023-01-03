/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:26 by dgross            #+#    #+#             */
/*   Updated: 2023/01/03 14:34:11 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>

static int	mini_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (ft_tolower(s1[i]) < s2[i])
			return (-1);
		if (ft_tolower(s1[i]) > s2[i])
			return (1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else if (s1[i] == '\0')
		return (-1);
	return (1);
}

int	ft_execute_builtin(t_koopa *shell, t_data *data)
{
	if (shell->skip == 1)
		return (0);
	if (!mini_strcmp(data->cmd_name, "cd"))
		shell->exit_code = ft_cd(shell, &data->cmd_line[1]);
	else if (!mini_strcmp(data->cmd_name, "echo"))
		shell->exit_code = ft_echo(data->cmd_line);
	else if (!mini_strcmp(data->cmd_name, "env"))
		shell->exit_code = ft_env(shell);
	else if (!mini_strcmp(data->cmd_name, "exit"))
		ft_exit(shell, data->cmd_line);
	else if (!mini_strcmp(data->cmd_name, "export"))
		shell->exit_code = ft_export(shell, data->cmd_line);
	else if (!mini_strcmp(data->cmd_name, "pwd"))
		shell->exit_code = ft_pwd();
	else if (!mini_strcmp(data->cmd_name, "unset"))
		shell->exit_code = ft_unset(shell, data->cmd_line);
	else
		return (1);
	shell->exit = BUILTIN;
	return (0);
}
