/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:40 by dgross            #+#    #+#             */
/*   Updated: 2023/01/04 21:29:54 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

int	reset_redir(t_koopa *shell, t_data *data)
{
	if (data->operator == PIPE && shell->redirect == 0)
	{
		shell->redirect = 1;
		shell->out = dup(shell->tmp_stdout);
		shell->in = dup(shell->tmp_stdin);
		return (1);
	}
	return (0);
}
