/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:58 by dgross            #+#    #+#             */
/*   Updated: 2022/12/03 11:19:30 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h> // malloc
#include <readline/readline.h> // readline
#include <readline/history.h> // readline

int	init_evnp(t_koopa *shell, char **envp)
{
	int					i;
	struct sigaction	s_sigaction;

	i = -1;
	// s_sigaction.sa_sigaction = ;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &s_sigaction, NULL); // ctrl - c
	sigaction(SIGQUIT, &s_sigaction, NULL); // ctrl - d
	shell->envp = ft_calloc(ft_ptrcnt(envp) + 1, sizeof(char *));
	if (shell->envp == NULL)
		print_error();
	while (envp[++i] != NULL)
		shell->envp[i] = ft_strdup(envp[i]);
	shell->envp[i] = NULL;
	return (0);
}

static int	init_koopa_shell(t_koopa *shell)
{
	shell = malloc(sizeof(t_koopa));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_koopa	*shell;
	struct	sigaction act;
	char	*str;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_signal_handler;
	sigaction(SIGQUIT, &act, 0);
	sigaction(SIGINT, &act, 0);
	ft_set_termianl();
	init_koopa_shell(shell);
	init_envp(shell, envp);
	argc = 0;
	argv = NULL;
	envp = NULL;
	while (1)
	{
		usleep(10);
		str = readline("👉 ");
		if (str == NULL)
		exit(0);
		free(str);
   }
	return (0);
}
