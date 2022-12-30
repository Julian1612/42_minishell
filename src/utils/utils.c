/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:01:00 by dgross            #+#    #+#             */
/*   Updated: 2022/12/30 15:04:14 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h> // free
#include <stdio.h>

char	*ft_addchar(char	*str, char c)
{
	char	*new_string;
	int		i;

	i = -1;
	new_string = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (str[++i] != '\0')
		new_string[i] = str[i];
	new_string[i++] = c;
	new_string[i] = '\0';
	free(str);
	return (new_string);
}

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
	if (name == NULL)
		return (NULL);
	if (ft_strncmp(name, "?", 1) == 0)
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
	return ("\0");
}

void	free_double(char **double_pointer)
{
	int	i;

	i = -1;
	while (double_pointer[++i] != NULL)
		free(double_pointer[i]);
	free(double_pointer);
}
