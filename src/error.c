/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:18:31 by dgross            #+#    #+#             */
/*   Updated: 2023/01/06 10:48:46 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <stdio.h> //perror	
#include <stdlib.h> // exit
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
