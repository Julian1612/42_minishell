/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:24 by dgross            #+#    #+#             */
/*   Updated: 2022/12/27 01:07:54 by dna              ###   ########.fr       */
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
	if (ft_strncmp(data->cmd_line[0], "../", 3) == 0)
		shell->file = data->cmd_line[0];
	else if (access(data->cmd_line[0], F_OK) == -1)
	{
		shell->path = ft_split(ft_getenv(shell, "PATH") + 5, ':');
		if (shell->path == NULL)
		{
			free_double(shell->path);
			printf("Error : shell->path\n");
		}
		shell->file = create_path(shell, data->cmd_name);
	}
	else
		shell->file = data->cmd_line[0];
}

void	ft_cmd(t_koopa *shell, t_data *data)
{
	close(shell->fd[0]);
	close(shell->fd[1]);
	prepare_execution(shell, data);
	execve(shell->file, data->cmd_line, shell->envp);
	printf("execve error\n");
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
		printf("execve error\n");
		exit(127);
	}
}

void	pipe_cmd(t_koopa *shell, t_data *data)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		write_to(shell, data);
		if (ft_execute_builtin(shell, data) == 0)
		{
			close(shell->fd[0]);
			close(shell->fd[1]);
			exit(0);
		}
		else
			ft_cmd(shell, data);
	}
}
