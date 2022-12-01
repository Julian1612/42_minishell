/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:59 by dgross            #+#    #+#             */
/*   Updated: 2022/12/01 16:12:07 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	i = -1;
	if (var_checker(shell, variable))
		return (0);
	tmp_envp = ft_calloc(ft_ptrcnt(shell->envp), sizeof(char *));
	while (shell->envp[++i] != NULL)
	{
		if (!ft_strncmp(shell->envp[i], variable, ft_name_len(variable)))
		{
			*tmp_envp = ft_strdup(shell->envp[i]);
			tmp_envp++;
		}
	}
	tmp_envp[i] = NULL;
	free_envp(shell);
	shell->envp = tmp_envp;
	return (0);
}
