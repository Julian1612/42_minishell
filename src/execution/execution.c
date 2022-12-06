/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/12/06 15:45:36 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // dup access fork
#include <sys/wait.h>
#include <stdio.h>

static void	open_pipe(t_koopa *shell)
{
	if (pipe(shell->fd) == -1)
	{
		printf("ERROR\n");
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
	else
		dup2(shell->stdout1, 1);
}

int	ft_execute(t_koopa *shell, t_data *data)
{
	shell->stdout1 = dup(STDOUT_FILENO);
	ft_redirection(shell, data);
	while (data != NULL)
	{
		if (data->operator == PIPE)
			open_pipe(shell);
		if (data->operator == CMD || data->operator == PIPE)
		{
			write_to(shell, data);
			ft_execute_builtin(shell, data);
			ft_execute_cmd(shell, data);
		}
		if (data->operator == PIPE)
			close_pipe(shell);
		data = data->next;
	}
	close(shell->out);
	return (0);
}
