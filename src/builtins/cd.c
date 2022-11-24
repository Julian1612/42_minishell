/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/11/24 19:33:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> //chdir
#include <stdlib.h> // getenv

static update_pwd()
{
	
}

int	ft_cd(t_koopa *shell) // only relative or absolute path 
{
	if (shell->argc == 1)
	{
		// wenn nur cd gecalled wird
		if(!chdir(getenv("HOME")))
		[
			/*error message*/		
		]
	}
	else
	{
		// wenn cd + path gecalled wird
		if (!chdir(shell->cmd_str[2]))
		{
			/*error message*/	
		}
			
	}
	// wenn alles geklappt hat wird pwd geupdated
	// entwerder die envp PWD editieren oder irgendwas anderes 
	update_pwd();
}