/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/11/23 14:08:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // dup

int	ft_execute(t_minishell *shell)
{
	int fd[2];
	int pid;

	fd[0] = dup(STDIN_FILENO);
	while (/* cmd_line nicht NULL ist*/)
	{
		pid = fork();
		if (pid == 0)
		{
			check_acces();
			if (execve(pipex->file, pipex->cmd, envp) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			
		}
	}
}
