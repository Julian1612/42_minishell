/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:59 by dgross            #+#    #+#             */
/*   Updated: 2022/12/08 17:00:57 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>
static int	var_checker(t_koopa *shell, char *variable)
{
	int	i;

	i = -1;
	while (shell->envp[++i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], variable, ft_name_len(variable)))
			return (1);
	}
	return (0);
}

int	ft_unset(t_koopa *shell, char *variable)
{
	char	**tmp_envp;
	int		i;
	int		k;

	k = 0;
	i = -1;
	if (!var_checker(shell, variable))
		return (0);
	tmp_envp = ft_calloc(ft_ptrcnt(shell->envp) + 2, sizeof(char *));
	while (shell->envp[++i] != NULL)
	{
		if (ft_strcmp(shell->envp[i], variable) == -1)
		{
			tmp_envp[k] = ft_strdup(shell->envp[i]);
			k++;
		}
	}
	tmp_envp[k] = NULL;
	free_envp(shell);
	shell->envp = tmp_envp;
	return (0);
}
