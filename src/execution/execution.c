/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/12/01 16:17:12 by dgross           ###   ########.fr       */
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
		if (ft_execute_builtin(shell, data))
			return (0);
		else
			ft_execute_cmd(shell, data);
		//while ()
		//{
		//	//watiing and get exec status from builtin and or cmd
		//}
		data = data->next;
	}
	return (0);
}
