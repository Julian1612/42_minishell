/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 19:38:18 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> //chdir
#include <stdlib.h> // getenv
#include <limits.h>

static void update_pwd(t_koopa *shell)
{
	// i guess deleting and adding the a new OLDPWD
	// in envp
	// wieder erst gucken wie wir das machen
	// edgecases etc
	/*brauchen jetzt eine funktion die wie getenv arbeitet aber für unser envp*/
	/*danach OLDPWD mit PWD ersetzten und PWD deine neuen path geben*/
	// herausfinden wie man den aktuelen path findet mit getcwd
	char buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX))

	
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
	update_pwd(); // OLDPWD
	return (0);// !exit status!
}