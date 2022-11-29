/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/11/29 14:15:41 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // chdir
#include <stdlib.h> // getenv
#include <limits.h> // [PATH_MAX]

// nochmal umschreiben ist irgendwie kacke geschrieben und muss aus pwd noch
// OLDPWD machen
static void	update_pwd(t_koopa *shell, t_data *data)
{
	char	pwd[PATH_MAX];
	char	*oldpwd;

	if (getcwd(pwd, PATH_MAX))
		print_error();
	else
	{
		oldpwd = ft_getenv(shell, "PWD");
		free(data->arg);
		data->arg = ft_strdup(pwd);
		ft_export(shell, data);
		free(data->arg);
		data->arg = ft_strdup(oldpwd);
		ft_export(shell, data);
	}
}

int	ft_cd(t_koopa *shell, t_data *data)
{
	if (data->argc == 1)
	{
		if (!chdir(getenv("HOME")))
		{
			print_error();
		}
	}
	else
	{
		if (!chdir(data->arg))
		{
			print_error();
		}
	}
	update_pwd(shell, data);
	return (0);
}