/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:40 by dgross            #+#    #+#             */
/*   Updated: 2023/01/07 17:20:35 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <unistd.h> // dup, close
#include <sys/stat.h> // fstat

int	reset_redir(t_koopa *shell, t_data *data)
{
	struct stat	file_stat;

	if (data->operator == PIPE && shell->redirect == 0)
	{
		shell->redirect = 1;
		if (fstat(shell->out, &file_stat) == 0)
			close(shell->out);
		shell->out = -1;
		dup2(shell->tmp_stdout, STDOUT_FILENO);
	}
	return (0);
}
