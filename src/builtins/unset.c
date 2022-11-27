/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:59 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 22:35:37 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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
