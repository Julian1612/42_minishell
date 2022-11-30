/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:24 by dgross            #+#    #+#             */
/*   Updated: 2022/11/30 16:09:14 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h> // dup access fork
#include <stdlib.h> // 

// nochmal überarbeiten sieht nicht richtig aus 
// path pfad nochmal neue machen sieht kacke aus
// vllt überlegen doch envp als stuct zu machen
// macht paar sachen einfacher
static void	*get_path(t_koopa *shell, t_data *data)
{
	char	**path;

	if (access(data->cmd_line[0], F_OK) == -1)
	{
		path = ft_split(ft_getenv(shell, "PATH") + 5, ':');
		if (path == NULL)
			print_error();
		shell->file = create_path(shell, path[0]);
		if (shell->file == NULL)
			printf_error();
	}
	else
	{
		shell->file = data->cmd_line[0];
		pipex->cmd = ft_split(cmd_str, ' ');
	}
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
	int	fd[2];
	int	pid;

	if (data->pipe == true)
		pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		get_path(shell, data);
		if (execve(/*file*/, data->cmd_line, shell->envp))
			printf_error();	
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
}
