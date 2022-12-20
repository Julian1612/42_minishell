/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:52 by dgross            #+#    #+#             */
/*   Updated: 2022/12/20 16:59:29 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> // dup access fork
#include <sys/wait.h> // waitpid
#include <stdio.h>
#include <stdlib.h> // exit

static int	check_input(char *arg, int size, t_koopa *shell)
{
	int	i;

	i = -1;
	while (arg[++i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
		{
			perror("minishell: exit: numeric argument required");
			exit(255);
		}
	}
	if (size > 2)
	{
		perror("minishell: exit:");
		shell->exit_status = 1;
		return (-1);
	}
	return (0);
}

void	ft_exit(t_koopa *shell, char **cmd_line)
{
	int	size;
	int	num;

	num = 0;
	if (cmd_line == NULL)
		exit(0);
	size = ft_ptrcnt(cmd_line);
	if (check_input(cmd_line[1], size, shell) == -1)
		return ;
	num = ft_atoi(cmd_line[1]);
	printf("exit\n");
	exit(num);
}
