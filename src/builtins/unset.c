/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:59 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 19:33:16 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int search_for_var(t_koopa *shell)
{
	int i;

	i = -1;
	while (shell->envp[++i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], shell->var, ft_name_len()))
			return (0);
	}
	return (1);
}

//unset values and attributes of variables and functions
// idee eine envp im struct haben und diese immer bearbeiten und
// sucht im envp nach der gesuchten variable
	// wenn es sie gibt wir sie gelöscht
	// im env sind keine zahlen also auch nach zahlen gucken
int ft_unset(t_koopa *shell) //unset values and attributes of variables and functions
{
	char **tmp_envp;
	int i;

	i = -1;
	shell->envp = ft_calloc(ft_ptrcnt(shell->envp), sizeof(char *));
	if (search_for_var(shell))
	{
		while (shell->envp[++i] != NULL)
		{
			if (shell->envp[i] != /*name_von_der_var*/)
			{
				*tmp_envp = ft_strdup(shell->envp[i]);
				tmp_envp++;
			}
		}
		tmp_envp[i] = NULL;
		free_evnp(shell);
		shell->envp = tmp_envp;
	}
	return (0);
}
