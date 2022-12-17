/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:24 by dgross            #+#    #+#             */
/*   Updated: 2022/12/17 18:15:43 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h> // dup access fork
#include <stdlib.h> // 
#include <stdio.h> // 

static char	*create_path(t_koopa *shell, char *cmd)
{
	int	i;

	i = -1;
	while (shell->path[++i])
	{
		shell->path[i] = ft_strjoin(shell->path[i], "/");
		shell->path[i] = ft_strjoin(shell->path[i], cmd);
		if (access(shell->path[i], X_OK) == 0)
			return (shell->path[i]);
	}
	return (NULL);
}

static void	prepare_execution(t_koopa *shell, t_data *data)
{
	if (access(data->cmd_line[0], X_OK) == -1)
	{
		shell->path = ft_split(ft_getenv(shell, "PATH") + 5, ':');
		if (shell->path == NULL)
		{
			free_double(shell->path);
			printf("Error\n");
		}
		shell->file = create_path(shell, data->cmd_name);
	}
	else
	{
		shell->file = data->cmd_line[0];
	}
}

void	ft_cmd(t_koopa *shell, t_data *data)
{
	close(shell->fd[0]);
	close(shell->fd[1]);
	prepare_execution(shell, data);
	execve(shell->file, data->cmd_line, shell->envp);
	printf("ERROR\n");
	exit(127);
}

void	ft_execute_cmd(t_koopa *shell, t_data *data)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		prepare_execution(shell, data);
		execve(shell->file, data->cmd_line, shell->envp);
		printf("Error\n");
		exit(127);
	}
}
