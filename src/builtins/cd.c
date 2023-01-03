/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2023/01/03 15:20:02 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // chdir
#include <stdlib.h> // getenv
#include <limits.h> // [PATH_MAX]
#include "libft.h"
#include <stdio.h>

static int	check_path(t_koopa *shell, char ***path, int *check)
{
	if (**path == NULL)
		return (0);
	if (ft_strcmp(**path, "-") == 0 || ft_strcmp(**path, "~-") == 0)
	{
		free(**path);
		**path = NULL;
		**path = ft_strdup(ft_getenv(shell, "OLDPWD") + 7);
		if (**path[0] == '\0')
		{
			print_error("cd", NULL, "OLDPWD not set");
			return (1);
		}
		*check = 1;
	}
	else if (ft_strcmp(**path, "~") == 0)
	{
		free(**path);
		**path = ft_strdup(ft_getenv(shell, "HOME"));
		if (**path[0] == '\0')
		{
			print_error("cd", NULL, "HOME not set");
			return (1);
		}
	}
	return (0);
}

static char	**to_double(char *str)
{
	char	**new;

	new = malloc(sizeof(char *) * 3);
	if (new == NULL)
		return (NULL);
	new[0] = ft_strdup("cd");
	new[1] = ft_strdup(str);
	new[2] = NULL;
	return (new);
}

static int	update_pwd(t_koopa *shell, int check)
{
	char	buf[PATH_MAX];
	char	*oldpwd;
	char	*pwd;

	pwd = getcwd(buf, PATH_MAX);
	if (pwd == NULL)
		return (1);
	else
	{
		oldpwd = ft_strjoin("OLDPWD=", ft_getenv(shell, "PWD=") + 4);
		ft_export(shell, to_double(oldpwd));
		pwd = ft_strjoin("PWD=", buf);
		ft_export(shell, to_double(pwd));
		free(oldpwd);
		free(pwd);
		oldpwd = NULL;
		pwd = NULL;
		if (check == 1)
			ft_pwd();
		return (0);
	}
	return (1);
}

int	ft_cd(t_koopa *shell, char **path)
{
	int	check;
	int	status;

	check = 0;
	status = check_path(shell, &path, &check);
	if (status != 0)
		return (status);
	if (*path == NULL)
	{
		if (chdir(ft_getenv(shell, "HOME=") + 5))
		{
			print_error("cd", NULL, "HOME not set");
			return (1);
		}		
	}
	else
	{	
		if (chdir(*path))
		{
			print_error(NULL, *path, NULL);
			return (1);
		}	
	}
	status = update_pwd(shell, check);
	return (status);
}
