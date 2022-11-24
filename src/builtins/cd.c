/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/11/24 15:09:45 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> //chdir
#include <stdlib.h> // getenv

int	ft_cd(t_minishell *shell)
{
	if (shell->argc == 1)
	{
		// wenn nur cd gecalled wird
		chdir(getenv("HOME"));
	}
	else
	{
		// wenn cd + path gecalled wird
		chdir(shell->cmd_str[2]);
	}
	// wenn alles geklappt hat wird pwd geupdated
}
