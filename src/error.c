/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:18:31 by dgross            #+#    #+#             */
/*   Updated: 2023/01/05 16:30:46 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h> //perror	
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // dup access fork

// gucken wie wir ne überall ausführbare error function hinbekommen
int	print_error(char *failed_cmd, char	*failed_arg, char *reason)
{
	ft_putstr_fd("minishell: ", 2);
	if (failed_cmd != NULL)
	{
		ft_putstr_fd(failed_cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (failed_arg != NULL)
	{
		ft_putstr_fd(failed_arg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (reason == NULL)
		perror(NULL);
	else
	{
		ft_putstr_fd(reason, 2);
		ft_putstr_fd("\n", 2);
	}
	return (0);
}

void	check_typ_of_error(char	*cmd)
{
	char	*check;

	check = ft_strchr(cmd, '/');
	if (check == NULL)
		print_error(cmd, NULL, "command not found");
	else
		print_error(cmd, NULL, NULL);
	exit(127);
}

int	garbage_bin(char *cmd)
{
	int	i;

	i = ft_strlen(cmd);
	if (access(cmd, F_OK) != -1)
		return (1);
	if (ft_strncmp(cmd, "/", 1) == 0)
		return (0);
	if (ft_strncmp(cmd, "../", 3) == 0 || ft_strncmp(cmd, "./", 2) == 0)
		return (0);
	return (1);
}
