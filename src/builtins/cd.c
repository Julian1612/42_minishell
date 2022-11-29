/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/11/29 11:46:02 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // chdir
#include <stdlib.h> // getenv
#include <limits.h> // [PATH_MAX]

static void	update_pwd(t_koopa *shell)
{
	char	pwd[PATH_MAX];
	char	*oldpwd;

	if (getcwd(pwd, PATH_MAX))
		print_error();
	else
	{
		oldpwd = ft_getenv("PWD");
		ft_export(shell);
		ft_export(shell);
	}
}

int	ft_cd(t_koopa *shell)
{
	if (shell->data->argc == 1)
	{
		if (!chdir(getenv("HOME")))
		{
			print_error();
		}
	}
	else
	{
		if (!chdir(shell->data->arg))
		{
			print_error();
		}
	}
	update_pwd(shell);
	return (0);
}