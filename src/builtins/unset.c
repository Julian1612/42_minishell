/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:59 by dgross            #+#    #+#             */
/*   Updated: 2022/12/27 14:23:11 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static int	input_check(char *variable)
{
	int	i;

	i = -1;
	if (variable[0] == '=' || ft_isdigit(variable[0]) || variable[0] == '\0')
		return (ERROR);
	while (variable[++i] != '\0')
	{
		if (!ft_isalnum(variable[i]) && variable[i] != '_' \
		&& variable[i] == '=')
			break ;
	}
	if (variable[i] != '\0')
	{
		print_error("unset", variable, "not a valid identifier");
		return (ERROR);
	}
	return (0);
}

static int	var_checker(t_koopa *shell, char *variable)
{
	int	i;

	i = -1;
	if (variable == NULL)
		return (0);
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
	if (input_check(variable) == ERROR)
		return (1);
	if (!var_checker(shell, variable))
		return (0);
	tmp_envp = ft_calloc(ft_ptrcnt(shell->envp) + 2, sizeof(char *));
	while (shell->envp[++i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], variable, ft_strlen(variable)) != 0)
		{
			tmp_envp[k] = ft_strdup(shell->envp[i]);
			k++;
		}
	}
	tmp_envp[k] = NULL;
	free_double(shell->envp);
	shell->envp = tmp_envp;
	return (0);
}
