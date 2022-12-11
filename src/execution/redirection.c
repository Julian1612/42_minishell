/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:09 by dgross            #+#    #+#             */
/*   Updated: 2022/12/11 12:04:05 by dgross           ###   ########.fr       */
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
		printf("ERROR\n");
		return (ERROR);
	}
	dup2(shell->in, STDIN_FILENO);
	close(shell->in);
	return (0);
}

static int	ft_redirect_outfile(t_koopa *shell, t_data *data)
{
	shell->out = open(data->cmd_line[0], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (shell->out == -1)
	{
		printf("ERROR\n");
		return (ERROR);
	}
	return (0);
}

static int	ft_append_outfile(t_koopa *shell, t_data *data)
{
	shell->out = open(data->cmd_line[0], O_CREAT | O_RDWR | O_APPEND, 0777);
	if (shell->out == -1)
	{
		printf("ERROR\n");
		return (ERROR);
	}
	return (0);
}

void	ft_redirection(t_koopa *shell, t_data *data)
{
	while (data != NULL)
	{
		if (data->operator == HEREDOC)
			ft_heredoc(shell, data);
		else if (data->operator == IN)
			ft_redirect_infile(shell, data);
		else if (data->operator == OUT)
			ft_redirect_outfile(shell, data);
		else if (data->operator == APPEND)
			ft_append_outfile(shell, data);
		data = data->next;
	}
}
