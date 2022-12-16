/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:01:00 by dgross            #+#    #+#             */
/*   Updated: 2022/12/15 14:40:09 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h> // free
#include <stdio.h> 
int	ft_name_len(char *variable)
{
	int	i;

	i = -1;
	if (variable == NULL)
		return (-1);
	while (variable[++i] != '\0')
	{
		if (variable[i] == '=')
			break ;
		if (variable[0] == '?')
			return (0);
	}
	return (i + 1);
}

char	*ft_getenv(t_koopa *shell, char *name)
{
	int	i;

	i = -1;
	if (!ft_strncmp(name, "?", 1))
	{
		free(name);
		name = ft_itoa(shell->exit_status);
		return (name);
	}
	while (shell->envp[++i] != NULL)
	{
		if (!ft_strncmp(shell->envp[i], name, ft_strlen(name)))
			return (shell->envp[i]);
	}
	return ("\n");
}

void	free_double(char **double_pointer)
{
	int	i;

	i = -1;
	while (double_pointer[++i] != NULL)
		free(double_pointer[i]);
	free(double_pointer);
}
