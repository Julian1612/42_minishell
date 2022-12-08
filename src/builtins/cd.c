/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/12/08 19:46:44 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // chdir
#include <stdlib.h> // getenv
#include <limits.h> // [PATH_MAX]
#include <stdio.h>
static int	update_pwd(t_koopa *shell)
{
	char	*pwd;
	char	*oldpwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (1);
	else
	{
		pwd = ft_strjoin("PWD=", pwd);
		ft_export(shell, pwd);
		oldpwd = ft_strjoin("OLDPWD=", ft_getenv(shell, "PWD") + 4);
		ft_export(shell, oldpwd);
		free(oldpwd);
		free(pwd);
		oldpwd = NULL;
		pwd = NULL;
		return (0);
	}
	return (1);
}

int	ft_cd(t_koopa *shell, char *path)
{
	if (path == NULL)
	{
		if (chdir(getenv("HOME")))
		{
			return (1);
		}		
	}
	else
	{
		if (chdir(path))
		{
			perror("OLDPWD");
			return (1);
		}	
	}
	update_pwd(shell);
	return (0);
}
