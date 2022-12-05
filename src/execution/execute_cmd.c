/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:24 by dgross            #+#    #+#             */
/*   Updated: 2022/12/05 13:17:49 by dgross           ###   ########.fr       */
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
		if (access(shell->path[i], F_OK) == 0)	
			return (shell->path[i]);
	}
	return (NULL);
}

static void	prepare_execution(t_koopa *shell, t_data *data)
{
	if (access(data->cmd_line[0], F_OK) == -1)
	{
		shell->path = ft_split(ft_getenv(shell, "PATH") + 5, ':');
		if (shell->path == NULL)
			;//print_error();
		shell->file = create_path(shell, data->cmd_name);
		if (shell->file == NULL)
			;//printf_error();
	}
	else
		shell->file = data->cmd_line[0];
}

static void	write_to(t_koopa *shell, t_data *data)
{
	if (data->next->operator == OUT || data->next->operator == APPEND)
	{
		dup2(shell->out, STDOUT_FILENO);
		close(shell->out);
	}
	else
	{
		dup2(shell->fd[1], STDOUT_FILENO);
	}
}

void	ft_execute_cmd(t_koopa *shell, t_data *data)
{
	int	pid;

	if (pipe(shell->fd) == -1)
		printf("ERROR\n");
	pid = fork();
	write_to(shell, data);
	if (pid == 0)
	{
		close(shell->fd[0]);
		close(shell->fd[1]);
		prepare_execution(shell, data);
		if (execve(shell->file, data->cmd_line, shell->envp))
			;//printf_error();	
	}
	else
	{
		dup2(shell->fd[0], shell->tmp_fd);
		close(shell->fd[0]);
		close(shell->fd[1]);
	}
}
