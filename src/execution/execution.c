/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2023/01/08 17:04:23 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h> // dup2 access fork close
#include <stdlib.h> // exit
#include <sys/stat.h> // fstat
#include <stdio.h>

static void	open_pipe(t_koopa *shell)
{
	if (pipe(shell->fd) == -1)
	{
		print_error("Pipe", NULL, "Not enough space/cannot \
		allocate memory");
		return ;
	}
}

static void	close_pipe(t_koopa *shell)
{
	dup2(shell->fd[0], STDIN_FILENO);
	close(shell->fd[1]);
	close(shell->fd[0]);
}

void	write_to(t_koopa *shell, t_data *tabel)
{
	if (tabel->next != NULL)
	{
		if (shell->out != -1)
		{
			if (shell->skip == 1)
				return ;
			dup2(shell->out, STDOUT_FILENO);
			close(shell->out);
			shell->out = -1;
		}
		else if (tabel->operator == PIPE)
			dup2(shell->fd[1], STDOUT_FILENO);
	}
	else if (tabel->operator != OUT && shell->out != -1)
	{
		dup2(shell->out, STDOUT_FILENO);
		close(shell->out);
		shell->out = -1;
	}
}

static	void	close_fd(t_koopa *shell)
{
	close(shell->out);
	shell->out = -1;
	dup2(shell->tmp_stdin, STDIN_FILENO);
	close(shell->tmp_stdin);
	dup2(shell->tmp_stdout, STDOUT_FILENO);
	close(shell->tmp_stdout);
}

int	ft_execute(t_koopa *shell, t_data *tabel)
{
	shell->head = tabel;
	if (check_for_heredoc(shell, tabel) == ERROR)
		return (ERROR);
	while (tabel != NULL)
	{
		if (ft_redirection(shell, tabel) == ERROR)
			break ;
		if (tabel->operator == PIPE)
		{
			open_pipe(shell);
			pipe_cmd(shell, tabel);
			close_pipe(shell);
		}
		else if (tabel->operator == CMD)
		{
			write_to(shell, tabel);
			if (ft_execute_builtin(shell, tabel) == 1)
				ft_execute_cmd(shell, tabel);
		}
		tabel = tabel->next;
	}
	close_fd(shell);
	get_exit_status(shell);
	return (0);
}
