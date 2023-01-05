/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:40 by dgross            #+#    #+#             */
/*   Updated: 2023/01/05 20:04:52 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <sys/stat.h>

int	reset_redir(t_koopa *shell, t_data *data)
{
	struct stat	file_stat;

	if (data->operator == PIPE && shell->redirect == 0)
	{
		shell->redirect = 1;
		if (fstat(shell->out, &file_stat) == 0)
			close(shell->out);
		shell->out = dup(shell->tmp_stdout);
		if (fstat(shell->in, &file_stat) == 0)
			close(shell->in);
		shell->in = dup(shell->tmp_stdin);
		return (1);
	}
	return (0);
}
