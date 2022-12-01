/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:54 by dgross            #+#    #+#             */
/*   Updated: 2022/12/01 16:09:22 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h> // free

static int	print_env(t_koopa *shell, char *variable)
{
	if (variable == NULL)
	{
		ft_env(shell);
		return (0);
	}
	return (1);
}

static int	already_exist(t_koopa *shell, char *variable)
{
	int	i;

	i = -1;
	while (shell->envp[++i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], variable, ft_name_len(variable)))
		{
			free(shell->envp[i]);
			shell->envp[i] = ft_strdup(variable);
			return (1);
		}
	}
	return (0);
}

int	ft_export(t_koopa *shell, char *variable)
{
	char	**tmp_envp;
	int		i;

	i = -1;
	if (print_env(shell, variable))
		return (0);
	if (already_exist(shell, variable))
		return (0);
	tmp_envp = ft_calloc(ft_ptrcnt(shell->envp) + 2, sizeof(char *));
	if (tmp_envp == NULL)
		//print_error();
	while (shell->envp[++i] != NULL)
		tmp_envp[i] = ft_strdup(shell->envp[i]);
	tmp_envp[i++] = variable;
	tmp_envp[i] = NULL;
	free_envp(shell);
	shell->envp = tmp_envp;
	return (0);
}
