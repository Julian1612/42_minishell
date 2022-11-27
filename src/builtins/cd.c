/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 10:15:28 by dna              ###   ########.fr       */
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
	/*brauchen jetzt eine funktion die wie getenv arbeitet aber für unser envp*/
	/*danach OLDPWD mit PWD ersetzten und PWD deine neuen path geben*/
	// herausfinden wie man den aktuelen path findet mit getcwd
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