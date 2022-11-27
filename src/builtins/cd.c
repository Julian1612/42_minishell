/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 22:48:45 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> //chdir
#include <stdlib.h> // getenv
#include <limits.h>

// i guess deleting and adding the a new OLDPWD
// in envp
// wieder erst gucken wie wir das machen
// edgecases etc
/*brauchen jetzt eine funktion die wie getenv arbeitet aber für unser envp*/
/*danach OLDPWD mit PWD ersetzten und PWD deine neuen path geben*/
// herausfinden wie man den aktuelen path findet mit getcwd
// entwerder export umbauen zu ft_export(shell, str)
// oder alles in den struct stdupen
// funktion schreiben die die namen von PWD zu OLDPWD ändert

static void update_pwd(t_koopa *shell)
{
	char new_pwd[PATH_MAX];
	char *oldpwd;

	if (getcwd(new_pwd, PATH_MAX))
		print_error();
	else
	{
		oldpwd = ft_getenv("PWD");
		ft_export(); // export new_pwd
		ft_export(); // export oldpwd
	}
	
}

int	ft_cd(t_koopa *shell)
{
	if (shell->argc == 1)
	{
		if(!chdir(getenv("HOME")))
		{
			print_error();		
		}
	}
	else
	{
		if (!chdir(shell->cmd_str[1]))
		{
			print_error();
		}
			
	}
	update_pwd(); // OLDPWD
	return (0);// !exit status!
}