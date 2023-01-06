/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:09 by dgross            #+#    #+#             */
/*   Updated: 2023/01/06 10:46:09 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <fcntl.h> // open
#include <unistd.h> // close, dup, dup2
#include <stdio.h> // NULL
#include <sys/stat.h> // fstat

static int	ft_redirect_infile(t_koopa *shell, t_data *data)
{
	struct stat	file_stat;

	if (fstat(shell->in, &file_stat) == 0)
		close(shell->in);
	shell->in = open(data->cmd_line[0], O_RDONLY);
	if (shell->in == -1)
	{
		print_error(NULL, data->cmd_line[0], NULL);
		return (ERROR);
	}
	return (0);
}

static int	ft_redirect_outfile(t_koopa *shell, t_data *data)
{
	struct stat	file_stat;

	if (fstat(shell->out, &file_stat) == 0)
		close(shell->out);
	shell->out = open(data->cmd_line[0], O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (shell->out == -1)
	{
		print_error(NULL, data->cmd_line[0], NULL);
		return (ERROR);
	}
	return (0);
}

static int	ft_append_outfile(t_koopa *shell, t_data *data)
{
	struct stat	file_stat;

	if (fstat(shell->out, &file_stat) == 0)
		close(shell->out);
	shell->out = open(data->cmd_line[0], O_CREAT | O_RDWR | O_APPEND, 00644);
	if (shell->out == -1)
	{
		shell->out = dup(shell->tmp_stdin);
		print_error(NULL, data->cmd_line[0], NULL);
		return (ERROR);
	}
	return (0);
}

int	check_for_heredoc(t_koopa *shell, t_data *tabel)
{
	struct stat	file_stat;

	shell->skip = 0;
	shell->redirect = 1;
	shell->tmp_stdin = dup(STDIN_FILENO);
	shell->tmp_stdout = dup(STDOUT_FILENO);
	shell->in = dup(STDIN_FILENO);
	shell->out = dup(STDOUT_FILENO);
	while (tabel != NULL)
	{
		if (tabel->operator == HEREDOC)
		{
			if (fstat(shell->in, &file_stat) == 0)
				close(shell->in);
			if (ft_heredoc(shell, tabel) == ERROR)
				return (ERROR);
			if (fstat(STDIN_FILENO, &file_stat) != 0)
				dup2(shell->tmp_stdin, STDIN_FILENO);
		}
		tabel = tabel->next;
	}
	return (0);
}

int	ft_redirection(t_koopa *shell, t_data *data)
{
	int	status;

	status = 0;
	if (ft_expand(shell, data) == ERROR)
	{
		shell->exit = BUILTIN;
		shell->exit_code = 1;
		return (ERROR);
	}
	while (data != NULL && shell->skip == 0 && shell->redirect == 1)
	{
		if (data->operator == PIPE)
			break ;
		else if (data->operator == IN && shell->skip == 0)
			status = ft_redirect_infile(shell, data);
		else if (data->operator == OUT && shell->skip == 0)
			status = ft_redirect_outfile(shell, data);
		else if (data->operator == APPEND && shell->skip == 0)
			status = ft_append_outfile(shell, data);
		if (status == ERROR)
			shell->skip = 1;
		data = data->next;
	}
	shell->redirect = 0;
	return (0);
}
