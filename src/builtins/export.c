/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:54 by dgross            #+#    #+#             */
/*   Updated: 2022/11/28 13:48:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int sort_envp(t_koopa *shell)
{
	// hehe push_swap
	// kp wie ich die argv reinbekomme um zu gucken ob
	// nur export gecallt wurde
	
}

static int already_exist(t_koopa *shell)
{
	int i;

	i = -1;
	while (shell->envp[++i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], shell->var, ft_name_len(shell->var)))
		{
			free(shell->envp[i]);
			shell->envp[i] = ft_strdup(shell->var);
			return (1);
		}
	}
	return (0);
}

int ft_export(t_koopa *shell) // edit environment variables
{
	char **tmp_envp;
	int i;

	i = -1;
	if (sort_envp(shell))
		return (0);
	if (aleady_exist(shell))
		return (0);
	tmp_envp = ft_calloc(ft_ptrcnt(shell->envp) + 2, sizeof(char *));
	if (tmp_envp == NULL)
		print_error();
	while (shell->envp[++i] != NULL)
		tmp_envp[i] = ft_strdup(shell->envp[i]);
	tmp_envp[i++] = shell->var;
	tmp_envp[i] = NULL;
	return (0);
}
