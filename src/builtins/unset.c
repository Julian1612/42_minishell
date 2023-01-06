/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:59 by dgross            #+#    #+#             */
/*   Updated: 2023/01/06 10:18:28 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static int	input_check(char *variable)
{
	int	i;

	i = -1;
	if (variable[0] == '=' || ft_isdigit(variable[0]) || variable[0] == '\0')
	{
		print_error("export", variable, "not a valid identifier");
		return (ERROR);
	}
	while (variable[++i] != '\0')
	{
		if (!ft_isalnum(variable[i]) && variable[i] != '_')
			break ;
	}
	if (variable[i] != '\0')
	{
		print_error("unset", variable, "not a valid identifier");
		return (ERROR);
	}
	return (0);
}

static int	var_checker(t_koopa *shell, char **variable)
{
	int	i;

	i = -1;
	if (*variable == NULL)
		return (0);
	*variable = ft_addchar(*variable, '=');
	while (shell->envp[++i] != NULL)
	{
		if (!ft_strncmp(shell->envp[i], *variable, ft_name_len(*variable)))
			return (1);
	}
	return (0);
}

static int	unset_var(t_koopa *shell, char **cmd_line, int i, int j)
{
	char	**tmp_envp;
	int		k;

	k = 0;
	tmp_envp = ft_calloc(ft_ptrcnt(shell->envp), sizeof(char *));
	if (tmp_envp == NULL)
	{
		print_error(NULL, "tmp_envp", "Not enough space/cannot \
		allocate memory");
		return (ERROR);
	}
	while (shell->envp[++i] != NULL)
	{
		if (ft_strncmp(shell->envp[i], cmd_line[j], \
		ft_strlen(cmd_line[j])) != 0)
			tmp_envp[k++] = ft_strdup(shell->envp[i]);
	}
	tmp_envp[k] = NULL;
	free_double(shell->envp);
	shell->envp = ft_arrdup(tmp_envp);
	return (0);
}

int	ft_unset(t_koopa *shell, char **cmd_line)
{
	int		end_status;
	int		status;
	int		j;
	int		i;

	j = 0;
	i = -1;
	status = 0;
	end_status = 0;
	while (cmd_line[++j] != NULL)
	{
		i = -1;
		status = input_check(cmd_line[j]);
		if (status != 0)
			end_status = 1;
		if (!var_checker(shell, &cmd_line[j]))
			status = 1;
		if (status == 0)
		{
			if (unset_var(shell, cmd_line, i, j) == ERROR)
				return (ERROR);
		}
	}
	return (end_status);
}
