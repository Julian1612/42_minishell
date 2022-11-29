/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:44 by dgross            #+#    #+#             */
/*   Updated: 2022/11/29 21:07:17 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // chdir
#include <stdlib.h> // getenv
#include <limits.h> // [PATH_MAX]

static void	update_pwd(t_koopa *shell, t_data *data)
{
	char	*pwd;
	char	*oldpwd;

	if (!getcwd(NULL, 0))
		print_error();
	else
	{
		pwd = ft_strjoin("PWD=", pwd);
		ft_export(shell,);
		oldpwd = ft_strjoin("OLDPWD=", ft_getenv(shell, "PWD"));
		ft_export(shell,);
		free(oldpwd);
		free(pwd);
		return (0);
	}
	return (1);
}

int	ft_cd(t_koopa *shell, t_data *data)
{
	if (data->argc == 1)
	{
		if (!chdir(getenv("HOME")))
		{
			print_error();
			return (1);
		}		
	}
	else
	{
		if (!chdir(data->cmd))
		{
			print_error();
			return (1);
		}	
	}
	update_pwd(shell, data);
	return (0);
}
