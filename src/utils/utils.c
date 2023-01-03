/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:01:00 by dgross            #+#    #+#             */
/*   Updated: 2023/01/03 15:05:25 by dgross           ###   ########.fr       */
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
		if (variable[0] == '?')
			return (0);
		if (variable[i] == '=')
			break ;
	}
	return (i + 1);
}

char	**ft_arrdup(char **old)
{
	char	**double_pointer;
	int		i;

	i = -1;
	double_pointer = ft_calloc(ft_ptrcnt(old) + 1, sizeof(char *));
	while (old[++i] != NULL)
		double_pointer[i] = ft_strdup(old[i]);
	double_pointer[i] = NULL;
	free_double(old);
	return (double_pointer);
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
	free(double_pointer[i]);
	free(double_pointer);
}
