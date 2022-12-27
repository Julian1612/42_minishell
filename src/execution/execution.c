/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/12/27 20:59:07 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // dup access fork
#include <sys/wait.h> // waitpid
#include <stdio.h>
#include <stdlib.h> // exit

static void	open_pipe(t_koopa *shell)
{
	if (pipe(shell->fd) == -1)
	{
		printf("Pipe ERROR\n");
		return ;
	}
}

static void	close_pipe(t_koopa *shell)
{
	dup2(shell->fd[0], STDIN_FILENO);
	close(shell->fd[0]);
	close(shell->fd[1]);
}

void	write_to(t_koopa *shell, t_data *data)
{
	if (data->next != NULL)
	{
		if (data->next->operator == OUT || data->next->operator == APPEND)
		{
			dup2(shell->out, STDOUT_FILENO);
			close(shell->out);
		}
		else if (data->operator == PIPE)
			dup2(shell->fd[1], STDOUT_FILENO);
	}
}

static	void	close_fd(t_koopa *shell)
{
	dup2(shell->tmp_stdin, STDIN_FILENO);
	close(shell->tmp_stdin);
	dup2(shell->tmp_stdout, STDOUT_FILENO);
	close(shell->tmp_stdout);
}

int	ft_execute(t_koopa *shell, t_data *data)
{
	if (ft_redirection(shell, data) == ERROR)
		return (ERROR);
	while (data != NULL)
	{
		if (data->operator == PIPE)
		{
			open_pipe(shell);
			pipe_cmd(shell, data);
			close_pipe(shell);
		}
		else if (data->operator == CMD)
		{
			write_to(shell, data);
			if (ft_execute_builtin(shell, data) == 1)
				ft_execute_cmd(shell, data);
		}
		data = data->next;
	}
	close_fd(shell);
	while (waitpid(0, &shell->exit_status, 0) > 0)
		;
	shell->exit_status = WEXITSTATUS(shell->exit_status);
	return (0);
}
