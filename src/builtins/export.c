/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:54 by dgross            #+#    #+#             */
/*   Updated: 2023/01/01 00:34:05 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h> // free
#include <stdio.h>

static int	check_var(char *variable)
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
	if (variable[i] == '\0' || variable[i] != '=')
	{
		print_error("export", variable, "not a valid identifier");
		return (ERROR);
	}
	return (0);
}

static void	print_env(t_koopa *shell)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (shell->envp[++i] != NULL)
	{
		printf("declare -x ");
		j = -1;
		while (shell->envp[i][++j] != '\0')
		{
			if (shell->envp[i][j] == '=')
			{
				printf("%c", shell->envp[i][j++]);
				printf("\"");
			}
			printf("%c", shell->envp[i][j]);
		}
		printf("\"\n");
	}
}

static int	already_exist(t_koopa *shell, char *variable)
{
	int	i;

	i = -1;
	if (variable == NULL)
	{
		print_env(shell);
		return (0);
	}
	if (check_var(variable) == ERROR)
		return (1);
	while (shell->envp[++i] != NULL)
	{
		if (!ft_strncmp(shell->envp[i], variable, ft_name_len(variable)))
		{
			free(shell->envp[i]);
			shell->envp[i] = ft_strdup(variable);
			return (1);
		}
	}
	return (0);
}

int	ft_export(t_koopa *shell, char **cmd_line)
{
	char	**tmp_envp;
	int		status;
	int		i;
	int		j;
	int		end_status;

	status = 0;
	end_status = 0;
	i = -1;
	j = 0;
	while (cmd_line[++j] != NULL)
	{
		i = -1;
		status = already_exist(shell, cmd_line[j]);
		if (status != ERROR)
			end_status = status;
		if (status == 0)
		{
			tmp_envp = ft_calloc(ft_ptrcnt(shell->envp) + 2, sizeof(char *));
			if (tmp_envp == NULL)
			{
				print_error(NULL, "tmp_envp", "Not enough space/cannot \
				allocate memory");
				return (ERROR);
			}
			while (shell->envp[++i] != NULL)
				tmp_envp[i] = ft_strdup(shell->envp[i]);
			tmp_envp[i++] = ft_strdup(cmd_line[j]);
			tmp_envp[i] = NULL;
			free_double(shell->envp);
			shell->envp = tmp_envp;
		}
	}
	return (end_status);
}
