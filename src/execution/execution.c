/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2023/02/15 19:25:06 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h> // dup2 access fork close
#include <stdlib.h> // exit
#include <sys/stat.h> // fstat

void	write_to(t_koopa *shell, t_data *table)
{
	if (table->next != NULL)
	{
		if (shell->out != -1)
		{
			if (shell->skip == 1)
				return ;
			dup2(shell->out, STDOUT_FILENO);
			close(shell->out);
			shell->out = -1;
		}
		else if (table->operator == PIPE)
			dup2(shell->fd[1], STDOUT_FILENO);
	}
	else if (table->operator != OUT && shell->out != -1)
	{
		dup2(shell->out, STDOUT_FILENO);
		close(shell->out);
		shell->out = -1;
	}
}

static void	execute_cmd(t_koopa *shell, t_data *table)
{
	int	pid;

	pid = -1;
	if (shell->nbr > 1 && is_builtin(table))
	{
		pid = fork();
		if (pid == 0)
		{
			ft_execute_builtin(shell, table),
			exit(shell->exit_code);
		}
	}
	else
	{
		if (ft_execute_builtin(shell, table) == 1)
			ft_execute_cmd(shell, table);
	}
}

int	ft_execute(t_koopa *shell, t_data *table)
{
	shell->head = table;
	if (check_for_heredoc(shell, table) == ERROR)
		return (ERROR);
	signal(SIGINT, SIG_IGN);
	while (table != NULL)
	{
		if (ft_redirection(shell, table) == ERROR)
			break ;
		if (table->operator == PIPE)
		{
			open_pipe(shell);
			pipe_cmd(shell, table);
			close_pipe(shell);
		}
		else if (table->operator == CMD)
		{
			write_to(shell, table);
			execute_cmd(shell, table);
		}
		table = table->next;
	}
	close_fd(shell);
	get_exit_status(shell);
	return (0);
}
