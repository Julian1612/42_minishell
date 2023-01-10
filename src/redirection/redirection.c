/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:09 by dgross            #+#    #+#             */
/*   Updated: 2023/01/10 10:26:45 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h> // close, dup, dup2
#include <stdio.h> // NULL
#include <sys/stat.h> // fstat

int	check_for_heredoc(t_koopa *shell, t_data *tabel)
{
	struct stat	file_stat;

	shell->skip = 0;
	shell->inter = 0;
	shell->tmp_stdin = dup(STDIN_FILENO);
	shell->tmp_stdout = dup(STDOUT_FILENO);
	shell->heredoc_file = -1;
	shell->nbr = -1;
	count_pipes(shell, tabel);
	while (tabel != NULL)
	{
		if (tabel->operator == HEREDOC)
		{
			if (shell->heredoc_file == -1)
				close(shell->heredoc_file);
			if (ft_heredoc(shell, tabel) == ERROR)
				return (ERROR);
			if (fstat(STDIN_FILENO, &file_stat) != 0)
				dup2(shell->tmp_stdin, STDIN_FILENO);
		}
		tabel = tabel->next;
	}
	return (0);
}

int	check_redir(t_data *data)
{
	if (data->operator == PIPE)
	{
		if (data->next != NULL && data->redir == data->next->redir)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

static void	exec_redirection(t_koopa *shell, t_data *data)
{
	int	status;

	status = 0;
	while (data != NULL && shell->skip == 0 && shell->inter < data->redir)
	{
		if (check_redir(data))
			break ;
		else if (data->operator == IN && shell->skip == 0)
			status = ft_redirect_infile(shell, data);
		else if (data->operator == OUT && shell->skip == 0)
			status = ft_redirect_outfile(shell, data);
		else if (data->operator == APPEND && shell->skip == 0)
			status = ft_append_outfile(shell, data);
		else if (data->operator == HEREDOC && shell->skip == 0)
			status = ft_redirect_heredoc(shell);
		if (status == ERROR)
			shell->skip = 1;
		data = data->next;
	}
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
	exec_redirection(shell, data);
	if (data == NULL)
		shell->inter++;
	if (data != NULL && (shell->inter < data->redir))
		shell->inter++;
	return (0);
}
