/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:40 by dgross            #+#    #+#             */
/*   Updated: 2023/01/05 14:22:12 by dgross           ###   ########.fr       */
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
