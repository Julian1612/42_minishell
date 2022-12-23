/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:58 by dgross            #+#    #+#             */
/*   Updated: 2022/12/23 21:00:29 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // malloc
#include <readline/readline.h> // readline
#include <readline/history.h> // readline
#include <fcntl.h> 
#include <limits.h>

int	init_envp(t_koopa *shell, char **envp)
{
	int					i;
	struct sigaction	s_sigaction;

	i = -1;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &s_sigaction, NULL);
	sigaction(SIGQUIT, &s_sigaction, NULL);
	shell->envp = ft_calloc(ft_ptrcnt(envp) + 1, sizeof(char *));
	if (shell->envp == NULL)
		return (-1);
	while (envp[++i] != NULL)
		shell->envp[i] = ft_strdup(envp[i]);
	shell->envp[i] = NULL;
	return (0);
}

//void	list_test(t_data *cmd_list)
//{
//	t_data	*cur = cmd_list;
//	int g = 1;
//	int y = 0;

// 	while (cur != NULL)
// 	{
// 		printf("%d. node: %s\n", g, cur->cmd_name);
// 		printf("cmd: %s\n", cur->cmd_name);
// 		while (cur->cmd_line[y] != NULL)
// 		{
// 			printf("%d.%d. cmd_line: %s\n", g, y, cur->cmd_line[y]);
// 			y++;
// 		}
// 		y = 0;
// 		printf("operator: %d\n", cur->operator);
// 		cur = cur->next;
// 		g++;
// 		printf("----------------------\n");
// 	}
//}

// void	arr_test(char **arr)
// {
// 	int	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		printf("%d. (%s)\n", i, arr[i]);
// 		i++;
// 	}
// }

// static void	free_all(t_koopa *shell, t_data *data)
// {
// 	while (data != NULL)
// 	{
// 		free_double(data->cmd_line);
// 		free(data->cmd_name);
// 		data = data->next;
// 	}
// 	free(data);
// 	free_double(shell->envp);
// 	free(shell->file);
// 	free(shell->line);
// 	free(shell);
// }

static int	execute_minishell(t_koopa *shell)
{
	t_data				*tabel;
	char				**token_arr;
	char				*cmd;

	while (TRUE)
	{
		cmd = readline("👉 ");
		if (cmd == NULL)
			break ;
		add_history(cmd);
		token_arr = tokenizer(cmd);
		if (token_arr == NULL)
			return (1);
		tabel = parser(token_arr);
		ft_execute(shell, tabel);
		free_double(token_arr);
		free(cmd);
	}
	return (0);
}

static t_koopa	*init_shell(void)
{
	t_koopa	*shell;

	shell = ft_calloc(1, sizeof(t_koopa));
	shell->envp = NULL;
	shell->path = NULL;
	shell->line = NULL;
	shell->file = NULL;
	shell->tmp_stdin = -1;
	shell->tmp_stdout = -1;
	shell->in = -1;
	shell->out = -1;
	shell->exit_status = -1;
	return (shell);
}

int	main(int argc, char **argv, char **envp)
{
	t_koopa				*shell;
	struct sigaction	act;

	(void)argv;
	argc++;
	shell = init_shell();
	init_envp(shell, envp);
	ft_terminal(1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_signal_handler;
	sigaction(SIGQUIT, &act, 0);
	sigaction(SIGINT, &act, 0);
	execute_minishell(shell);
	ft_terminal(0);
	return (0);
}
