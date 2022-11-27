/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:01:00 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 19:19:24 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h> // free

char *ft_getenv(t_koopa *shell, char *name)
{
	int i;

	i = -1;
	while(shell->envp[++i] != NULL)
	{
		if(ft_strncmp(shell->envp[i], name, ft_strlen(name)))
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
