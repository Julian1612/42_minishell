/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:59 by dgross            #+#    #+#             */
/*   Updated: 2022/11/28 16:25:16 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int var_check(t_koopa *shell)
{
	int i;

	i = -1;
	while (shell->envp[++i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], shell->var, ft_name_len(shell->var)))
			return (1);
	}
	return (0);
} 
	
int ft_unset(t_koopa *shell)
{
	char **tmp_envp;
	int i;

	i = -1;
	if (var_checker(shell))
		return (0);
	tmp_envp = ft_calloc(ft_ptrcnt(shell->envp), sizeof(char *));
	while (shell->envp[++i] != NULL)
	{
		if (!ft_strncmp(shell->envp[i], shell->var, ft_name_len(shell->var)))
		{
			*tmp_envp = ft_strdup(shell->envp[i]);
			tmp_envp++;
		}
	}
	tmp_envp[i] = NULL;
	free_evnp(shell);
	shell->envp = tmp_envp;
	return (0);
}
