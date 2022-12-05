/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:58 by dgross            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/05 15:59:20 by jschneid         ###   ########.fr       */
=======
/*   Updated: 2022/12/05 13:37:46 by dgross           ###   ########.fr       */
>>>>>>> 8a5a99c698573f00de803e2a591a23be244f6a09
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h> // malloc
#include <readline/readline.h> // readline
#include <readline/history.h> // readline

int	init_envp(t_koopa *shell, char **envp)
{
	int					i;
	struct sigaction	s_sigaction;

	i = -1;
	// s_sigaction.sa_sigaction = ;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &s_sigaction, NULL); // ctrl - c
	sigaction(SIGQUIT, &s_sigaction, NULL); // ctrl - d
	shell->envp = ft_calloc(ft_ptrcnt(envp) + 1, sizeof(char *));
	// if (shell->envp == NULL)
		// print_error();
	while (envp[++i] != NULL)
		shell->envp[i] = ft_strdup(envp[i]);
	shell->envp[i] = NULL;
	return (0);
}

// static int	init_koopa_shell(t_koopa *shell)
// {
// 	shell = malloc(sizeof(t_koopa));
// 	return (0);
// }

int	main(int argc, char **argv, char **envp)
{
	// t_koopa	*shell;
	struct	sigaction act;
	char	*cmd;

	// shell = NULL;
	// init_koopa_shell(shell);
	// init_envp(shell, envp);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_signal_handler;
	sigaction(SIGQUIT, &act, 0);
	sigaction(SIGINT, &act, 0);
	argc = 0;
	argv = NULL;
	envp = NULL;
	while (1)
	{
		cmd = readline("👉 ");
		if (cmd == NULL)
		exit(0);
		tokenizer(cmd);
		free(cmd);
   }
	return (0);
}
