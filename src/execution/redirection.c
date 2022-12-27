/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:09 by dgross            #+#    #+#             */
/*   Updated: 2022/12/27 22:22:37 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h> // open
#include <unistd.h> // close
#include <stdio.h>

static int	ft_redirect_infile(t_koopa *shell, t_data *data)
{
	shell->in = open(data->cmd_name, O_RDONLY);
	if (shell->in == -1)
	{
		print_error(NULL, data->cmd_line[0], NULL);
		return (ERROR);
	}
	dup2(shell->in, STDIN_FILENO);
	close(shell->in);
	return (0);
}

static int	ft_redirect_outfile(t_koopa *shell, t_data *data)
{
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
	shell->out = open(data->cmd_line[0], O_CREAT | O_RDWR | O_APPEND, 00644);
	if (shell->out == -1)
	{
		print_error(NULL, data->cmd_line[0], NULL);
		return (ERROR);
	}
	return (0);
}

int	ft_redirection(t_koopa *shell, t_data *data)
{
	int	status;

	status = 0;
	shell->tmp_stdin = dup(STDIN_FILENO);
	shell->tmp_stdout = dup(STDOUT_FILENO);
	while (data != NULL)
	{
		if (data->operator == HEREDOC)
			status = ft_heredoc(shell, data);
		else if (data->operator == IN)
			status = ft_redirect_infile(shell, data);
		else if (data->operator == OUT)
			status = ft_redirect_outfile(shell, data);
		else if (data->operator == APPEND)
			status = ft_append_outfile(shell, data);
		if (status != 0)
			return (status);
		ft_expand(shell, data);
		data = data->next;
	}
	return (0);
}
