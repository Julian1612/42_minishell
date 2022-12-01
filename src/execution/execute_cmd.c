/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:24 by dgross            #+#    #+#             */
/*   Updated: 2022/12/01 10:12:20 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h> // dup access fork
#include <stdlib.h> // 

static void	*prepare_execution(t_koopa *shell, t_data *data)
{
	if (access(data->cmd_line[0], F_OK) == -1)
	{
		shell->path = ft_split(ft_getenv(shell, "PATH") + 5, ':');
		if (shell->path == NULL)
			print_error();
		shell->file = create_path(shell, data->cmd_name);
		if (shell->file == NULL)
			printf_error();
	}
	else
		shell->file = data->cmd_line[0];
}

static char	*create_path(t_koopa *shell, char *cmd)
{
	int	i;

	i = -1;
	while (shell->path[++i])
	{
		shell->path[i] = ft_strjoin(shell->path[i], "/");
		shell->path[i] = ft_strjoin(shell->path[i], cmd);
		if (access(shell->path[i], F_OK) == 0)	
			return (shell->path[i]);
	}
	return (NULL);
}

void	ft_execute_cmd(t_koopa *shell, t_data *data)
{
	int	pid;

	if (data->pipe == true)
		pipe(shell->fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(shell->fd[1], STDOUT_FILENO);
		close(shell->fd[0]);
		close(shell->fd[1]);
		prepare_execution(shell, data);
		if (execve(shell->file, data->cmd_line, shell->envp))
			printf_error();	
	}
	else
	{
		dup2(shell->fd[0], STDIN_FILENO);
		close(shell->fd[0]);
		close(shell->fd[1]);
	}
}
