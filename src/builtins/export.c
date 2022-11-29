/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:54 by dgross            #+#    #+#             */
/*   Updated: 2022/11/29 14:03:20 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sort_envp(t_koopa *shell)
{
	// hehe push_swap
	// kp wie ich die argv reinbekomme um zu gucken ob
	// nur export gecallt wurde
}

static int	already_exist(t_koopa *shell, t_data *data)
{
	int	i;

	i = -1;
	while (shell->envp[++i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], data->arg, ft_name_len(data->cmd)))
		{
			free(shell->envp[i]);
			shell->envp[i] = ft_strdup(data->arg);
			return (1);
		}
	}
	return (0);
}

int	ft_export(t_koopa *shell, t_data *data)
{
	char	**tmp_envp;
	int		i;

	i = -1;
	if (sort_envp(shell))
		return (0);
	if (aleady_exist(shell, data))
		return (0);
	tmp_envp = ft_calloc(ft_ptrcnt(shell->envp) + 2, sizeof(char *));
	if (tmp_envp == NULL)
		print_error();
	while (shell->envp[++i] != NULL)
		tmp_envp[i] = ft_strdup(shell->envp[i]);
	tmp_envp[i++] = data->arg;
	tmp_envp[i] = NULL;
	return (0);
}
