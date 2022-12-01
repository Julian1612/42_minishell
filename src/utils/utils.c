/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:01:00 by dgross            #+#    #+#             */
/*   Updated: 2022/12/01 16:21:29 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h> // free

int	ft_name_len(char *variable)
{
	int	i;

	i = -1;
	if (variable == NULL)
		return (-1);
	while (variable[++i] != '\0')
		if (variable[i] == '=')
			break ;
	return (i + 1);
}

char	*ft_getenv(t_koopa *shell, char *name)
{
	int	i;

	i = -1;
	while (shell->envp[++i] != NULL)
	{
		if (!ft_strncmp(shell->envp[i], name, ft_strlen(name)))
			return (shell->envp[i]);
	}
	return (NULL);
}

void	free_envp(t_koopa *shell)
{
	int	i;

	i = -1;
	while (shell->envp[++i] != NULL)
		free(shell->envp[i]);
	free(shell->envp);
}
