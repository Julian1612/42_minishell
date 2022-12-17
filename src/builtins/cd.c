/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/12/17 18:13:36 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // chdir
#include <stdlib.h> // getenv
#include <limits.h> // [PATH_MAX]
#include "libft.h"
#include <stdio.h>

static int	update_pwd(t_koopa *shell)
{
	char	buf[PATH_MAX];
	char	*oldpwd;
	char	*pwd;

	pwd = getcwd(buf, PATH_MAX);
	if (pwd == NULL)
		return (1);
	else
	{
		oldpwd = ft_strjoin("OLDPWD=", ft_getenv(shell, "PWD") + 4);
		ft_export(shell, oldpwd);
		pwd = ft_strjoin("PWD=", buf);
		ft_export(shell, pwd);
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
			perror("HOME");
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
