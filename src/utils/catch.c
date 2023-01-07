/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:07:42 by dna               #+#    #+#             */
/*   Updated: 2023/01/07 15:13:55 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h> // access, close
#include <stdlib.h> // exit

void	handle_null(t_koopa *shell, t_data *data)
{
	if (data->cmd_name == NULL)
	{
		close(shell->fd[0]);
		write(shell->fd[1], "", 0);
		dup2(shell->fd[1], STDOUT_FILENO);
		close(shell->fd[1]);
		exit(0);
	}
}

int	garbage_bin(char *cmd)
{
	if (access(cmd, F_OK) != -1)
		return (1);
	if (ft_strncmp(cmd, "/", 1) == 0)
		return (0);
	if (ft_strncmp(cmd, "../", 3) == 0 || ft_strncmp(cmd, "./", 2) == 0)
		return (0);
	return (1);
}
