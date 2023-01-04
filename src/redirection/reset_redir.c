/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:40 by dgross            #+#    #+#             */
/*   Updated: 2023/01/04 16:11:06 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reset_redir(t_koopa *shell, t_data *data)
{
	if (data->operator == PIPE)
	{
		shell->redirect = 1;
		return (1);
	}
	return (0);
}
