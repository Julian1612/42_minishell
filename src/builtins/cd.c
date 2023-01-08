/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2023/01/08 10:35:32 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <unistd.h> // chdir
#include <stdlib.h> // getenv, free, malloc
#include <limits.h> // [PATH_MAX]

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

char	**to_double(char *str)
{
	char	**new;

	new = malloc(sizeof(char *) * 3);
	if (new == NULL)
		return (NULL);
	new[0] = ft_strdup("koopa_shell");
	new[1] = ft_strdup(str);
	new[2] = NULL;
	free(str);
	return (new);
}

static int	update_pwd(t_koopa *shell, int check)
{
	char	buf[PATH_MAX];
	char	*oldpwd;
	char	*pwd;
	char	**oldpwd_arr;
	char	**pwd_arr;

	pwd = getcwd(buf, PATH_MAX);
	if (pwd == NULL)
		return (1);
	else
	{
		oldpwd = ft_strjoin("OLDPWD=", ft_getenv(shell, "PWD=") + 4);
		oldpwd_arr = to_double(oldpwd);
		ft_export(shell, oldpwd_arr);
		pwd = ft_strjoin("PWD=", buf);
		pwd_arr = to_double(pwd);
		ft_export(shell, pwd_arr);
		free_double(pwd_arr);
		free_double(oldpwd_arr);
		if (check == 1)
			ft_pwd();
		return (0);
	}
	return (1);
}

static int	ft_change_dir(t_koopa *shell, char **path)
{
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
	return (0);
}

int	ft_cd(t_koopa *shell, t_data *data, char **path)
{
	int	check;

	check = 0;
	if (ft_strcmp(data->cmd_name, "CD") == 0)
		return (0);
	if (check_path(shell, &path, &check) != 0)
		return (1);
	if (ft_change_dir(shell, path) != 0)
		return (1);
	if (update_pwd(shell, check) != 0)
		return (1);
	return (0);
}
