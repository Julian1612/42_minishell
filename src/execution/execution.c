/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/12/05 13:18:51 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // dup access fork
#include <sys/wait.h>

int	ft_execute(t_koopa *shell, t_data *data)
{
	ft_redirection(shell, data);
	while (data != NULL)
	{
		if (data->operator == PIPE || data->operator == CMD)
		{
			ft_execute_builtin(shell, data);
			ft_execute_cmd(shell, data);
		}
		data = data->next;
	}
	close(shell->tmp_fd);
	close(shell->out);
	return (0);
}
