/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:26 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 10:42:33 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// checken welcher builtin ausgeführt werden soll
// und dann ausführen 
int ft_execute_builtins(t_koopa *shell)
{
	//wahrscheinlich hier auch dupen aber mal gucken vllt machen wir das in redirect aber glaube nicht
	if (ft_strcmp(shell->cmd, "cd"))
		ft_cd();
	else if (ft_strcmp(shell->cmd, "echo"))
		ft_echo();
	else if (ft_strcmp(shell->cmd, "env"))
		ft_env();
	else if (ft_strcmp(shell->cmd, "exit"))
		ft_exit();
	else if (ft_strcmp(shell->cmd, "export"))
		ft_export();
	else if (ft_strcmp(shell->cmd, "pwd"))
		ft_pwd();
	else if (ft_strcmp(shell->cmd, "unset"))
		ft_unset();
	else
		print_error(); // weiss nicht ob wir immer hier exiten und zurück zum promt gehen oder was machen
	return (0);
}