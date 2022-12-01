/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:09 by dgross            #+#    #+#             */
/*   Updated: 2022/12/01 16:18:29 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h> // open
#include <unistd.h> // close

static int	ft_redirect_infile(t_koopa *shell, t_data *data)
{
	shell->infile = open(data->cmd_line[0], O_RDONLY);
	if (shell->infile == -1)
		;//print_error();
	close(shell->tmp_fd);
	dup2(shell->tmp_fd, shell->infile);
	close(shell->infile);
	return (0);
}

static int	ft_redirect_outfile(t_koopa *shell, t_data *data)
{
	shell->outfile = open(data->cmd_line[0], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (shell->outfile == -1)
		;//print_error();
	return (0);
}

void	ft_redirection(t_koopa *shell, t_data *data)
{
	if (data->operator == 'h')
	{
		;//ft_here_doc(shell, data);
	}
	else if (data->operator == '<')
	{
		ft_redirect_infile(shell, data);
	}
	else if (data->operator == '>')
	{
		ft_redirect_outfile(shell, data);
	}
}
