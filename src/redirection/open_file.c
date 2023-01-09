/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:41:13 by dgross            #+#    #+#             */
/*   Updated: 2023/01/09 18:56:38 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h> // close, dup, dup2
#include <stdio.h> // NULL
#include <sys/stat.h> // fstat
#include <fcntl.h> // open

int	ft_redirect_infile(t_koopa *shell, t_data *data)
{
	struct stat	file_stat;

	if (fstat(shell->in, &file_stat) == 0)
		close(shell->in);
	if (ft_expand(shell, data) == ERROR)
	{
		shell->exit = BUILTIN;
		shell->exit_code = 1;
		return (ERROR);
	}
	shell->in = open(data->cmd_line[0], O_RDONLY);
	if (shell->in == -1)
	{
		print_error(NULL, data->cmd_line[0], NULL);
		return (ERROR);
	}
	dup2(shell->in, STDIN_FILENO);
	close(shell->in);
	return (0);
}

int	ft_redirect_outfile(t_koopa *shell, t_data *data)
{
	if (shell->out != -1)
	{
		close(shell->out);
		shell->out = -1;
	}
	if (ft_expand(shell, data) == ERROR)
	{
		shell->exit = BUILTIN;
		shell->exit_code = 1;
		return (ERROR);
	}
	shell->out = open(data->cmd_line[0], O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (shell->out == -1)
	{
		print_error(NULL, data->cmd_line[0], NULL);
		return (ERROR);
	}
	return (0);
}

int	ft_redirect_heredoc(t_koopa *shell)
{
	dup2(shell->heredoc_file, STDIN_FILENO);
	close(shell->heredoc_file);
	shell->heredoc_file = -1;
	return (0);
}

int	ft_append_outfile(t_koopa *shell, t_data *data)
{
	if (shell->out != -1)
	{
		close(shell->out);
		shell->out = -1;
	}
	if (ft_expand(shell, data) == ERROR)
	{
		shell->exit = BUILTIN;
		shell->exit_code = 1;
		return (ERROR);
	}
	shell->out = open(data->cmd_line[0], O_CREAT | O_RDWR | O_APPEND, 00644);
	if (shell->out == -1)
	{
		print_error(NULL, data->cmd_line[0], NULL);
		return (ERROR);
	}
	return (0);
}
