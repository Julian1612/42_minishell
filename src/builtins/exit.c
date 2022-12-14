/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:52 by dgross            #+#    #+#             */
/*   Updated: 2023/01/10 12:14:02 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <unistd.h> // write
#include <stdlib.h> // exit

static void	exit_check(t_koopa *shell, char *arg, int *i, int print)
{
	if (ft_isdigit(arg[*i]) == 0)
	{
		if (print == 1)
			write(2, "exit\n", 5);
		print_error("exit", arg, "numeric argument required");
		free_data(shell->head);
		free_shell(shell);
		exit(255);
	}
}

static int	check_input(char *arg, int size, t_koopa *shell, int print)
{
	int	i;

	i = -1;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[++i] != '\0')
	{
		exit_check(shell, arg, &i, print);
	}
	if (size > 2)
	{
		if (print == 1)
			write(2, "exit\n", 5);
		print_error("exit", NULL, "too many arguments");
		shell->exit_code = 1;
		return (-1);
	}
	return (0);
}

void	ft_exit(t_koopa *shell, char **cmd_line, int print)
{
	int	size;
	int	num;

	num = 0;
	if (cmd_line[1] == NULL)
	{
		free_data(shell->head);
		free_shell(shell);
		if (print == 1)
			write(2, "exit\n", 5);
		exit(0);
	}
	size = ft_ptrcnt(cmd_line);
	if (check_input(cmd_line[1], size, shell, print) == -1)
		return ;
	num = ft_atoi(cmd_line[1]);
	if (print == 1)
		write(2, "exit\n", 5);
	free_data(shell->head);
	free_shell(shell);
	exit(num);
}
