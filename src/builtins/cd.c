/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/11/26 15:13:57 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> //chdir
#include <stdlib.h> // getenv

static void update_pwd(t_koopa *shell)
{
	// i guess deleting and adding the a new OLDPWD
	// in envp
	// wieder erst gucken wie wir das machen
	// edgecases etc 	
}

int	ft_cd(t_koopa *shell) // only relative or absolute path 
{
	if (shell->argc == 1)
	{
		// wenn nur cd gecalled wird
		if(!chdir(getenv("HOME")))
		{
			/*error message*/		
		}
	}
	else
	{
		// wenn cd + path gecalled wird
		if (!chdir(shell->cmd_str[1]))
		{
			/*error message*/	
		}
			
	}
	update_pwd();
	return (0);// !exit status!
}