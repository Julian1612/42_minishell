/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:26 by dgross            #+#    #+#             */
/*   Updated: 2023/02/15 19:23:38 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <unistd.h> // fork
#include <stdlib.h> // exit

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

int	is_builtin(t_data *data)
{
	if (!ft_strcmp(data->cmd_name, "cd"))
		return (1);
	else if (!mini_strcmp(data->cmd_name, "echo"))
		return (1);
	else if (!mini_strcmp(data->cmd_name, "env"))
		return (1);
	else if (!ft_strcmp(data->cmd_name, "exit"))
		return (1);
	else if (!ft_strcmp(data->cmd_name, "export"))
		return (1);
	else if (!mini_strcmp(data->cmd_name, "pwd"))
		return (1);
	else if (!ft_strcmp(data->cmd_name, "unset"))
		return (1);
	else
		return (0);
}

int	ft_execute_builtin(t_koopa *shell, t_data *data)
{
	if (shell->skip == 1)
		return (0);
	if (!ft_strcmp(data->cmd_name, "cd"))
		shell->exit_code = ft_cd(shell, data, &data->cmd_line[1]);
	else if (!mini_strcmp(data->cmd_name, "echo"))
		shell->exit_code = ft_echo(data->cmd_line);
	else if (!mini_strcmp(data->cmd_name, "env"))
		shell->exit_code = ft_env(shell);
	else if (!ft_strcmp(data->cmd_name, "exit"))
	{
		if (shell->nbr > 1)
			ft_exit(shell, data->cmd_line, 0);
		else
			ft_exit(shell, data->cmd_line, 1);
	}
	else if (!ft_strcmp(data->cmd_name, "export"))
		shell->exit_code = ft_export(shell, data->cmd_line);
	else if (!mini_strcmp(data->cmd_name, "pwd"))
		shell->exit_code = ft_pwd();
	else if (!ft_strcmp(data->cmd_name, "unset"))
		shell->exit_code = ft_unset(shell, data->cmd_line);
	else
		return (1);
	shell->exit = BUILTIN;
	return (0);
}
