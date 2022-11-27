/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:01:00 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 22:35:47 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h> // free

int ft_name_len(char *name)
{
	int i;

	if (name == NULL)
		return (-1);
	i = ft_strchr(name, '=');
	return (i + 1);
}

char *ft_getenv(t_koopa *shell, char *name)
{
	int i;

	i = -1;
	while (shell->envp[++i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], name, ft_strlen(name)))
			return (shell->envp[i]);
	}
	return (NULL);
}

void free_evnp(t_koopa *shell)
{
	int i;

	i = -1;
	while (shell->envp[++i] != NULL)
		free(shell->envp[i]);
	free(shell->envp);
}
