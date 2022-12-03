/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/12/03 10:57:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // dup access fork

int	ft_execute(t_koopa *shell, t_data *data)
{
	shell->tmp_fd = dup(STDIN_FILENO);
	while (data != NULL)
	{
		ft_redirection(shell, data);
		ft_execute_builtin(shell, data);
		ft_execute_cmd(shell, data);
		data = data->next;
	}
	return (0);
}
