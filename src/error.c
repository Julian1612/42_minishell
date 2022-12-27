/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:18:31 by dgross            #+#    #+#             */
/*   Updated: 2022/12/27 16:37:33 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h> //perror	
#include <errno.h>
#include <string.h>

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
