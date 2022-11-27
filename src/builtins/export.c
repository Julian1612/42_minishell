/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:54 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 10:34:26 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// i guess envp mit getenv oder mit der main ins struct packen und dann 
// hier editieren mit strjoin oder so gleich dann bei unset
// export funkiton noch hinzufügen wenn nur export gecallt wird muss irgendwie
// eine alphabetisch sortierte env list geprintet werden
// nachgucken was es noch so gibt !!
int ft_export(t_koopa *shell) // edit environment variables
{
	char **tmp_envp;
	int i;

	i = -1;
	tmp_envp = ft_calloc(ft_ptrcnt(shell->envp) + 2, sizeof(char *));
	if (tmp_envp == NULL)
		print_error();
	while (shell->envp[++i] != NULL)
		tmp_envp[i] = ft_strdup(shell->envp[i]);
	tmp_envp[i++] = shell->new_var;
	tmp_envp[i] = NULL;
	return (0);
}