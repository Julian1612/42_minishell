/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:58 by dgross            #+#    #+#             */
/*   Updated: 2022/12/18 22:23:13 by dgross           ###   ########.fr       */
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
	if (shell->envp == NULL)
		return (-1);
	while (envp[++i] != NULL)
		shell->envp[i] = ft_strdup(envp[i]);
	shell->envp[i] = NULL;
	return (0);
}

void	list_test(t_data *cmd_list)
{
	t_data	*cur = cmd_list;
	int g = 1;
	int y = 0;

	while (cur != NULL)
	{
		printf("%d. node: %s\n", g, cur->cmd_name);
		printf("cmd: %s\n", cur->cmd_name);
		while (cur->cmd_line[y] != NULL)
		{
			printf("%d.%d. cmd_line: %s\n", g, y, cur->cmd_line[y]);
			y++;
		}
		y = 0;
		printf("operator: %d\n", cur->operator);
		cur = cur->next;
		g++;
		printf("----------------------\n");
	}
}

void	arr_test(char **arr)
{
	int	i = 0;
	while (arr[i] != NULL)
	{
		printf("%d. %s\n", i, arr[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_koopa				*shell;
	struct sigaction	act;
	char				*cmd;
	char				**token_arr;
	t_data				*data;

	shell = ft_calloc(1, sizeof(t_koopa));
	init_envp(shell, envp);
	ft_set_termianl();
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_signal_handler;
	sigaction(SIGQUIT, &act, 0);
	sigaction(SIGINT, &act, 0);
	argc++;
	(void)argv;
	(void)envp;
	while (1)
	{
		cmd = readline("👉 ");
		if (cmd == NULL)
			break ;
		add_history(cmd);
		token_arr = tokenizer(cmd);
		//arr_test(token_arr);
		if (token_arr == NULL)
			return (1);
		data = parser(token_arr);
		//list_test(data);
		ft_execute(shell, data);
		free(cmd);
	}
	return (0);
}
