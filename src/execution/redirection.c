/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:09 by dgross            #+#    #+#             */
/*   Updated: 2023/01/01 17:19:46 by dgross           ###   ########.fr       */
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
	while (data != NULL && shell->skip == 0)
	{
		if (data->operator == IN && shell->skip == 0)
			status = ft_redirect_infile(shell, data);
		else if (data->operator == OUT && shell->skip == 0)
			status = ft_redirect_outfile(shell, data);
		else if (data->operator == APPEND && shell->skip == 0)
			status = ft_append_outfile(shell, data);
		if (status == ERROR)
			shell->skip = 1;
		if (shell->skip == 0)
			ft_expand(shell, data);
		data = data->next;
	}
	return (0);
}
