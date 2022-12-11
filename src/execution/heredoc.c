/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:39 by dgross            #+#    #+#             */
/*   Updated: 2022/12/11 18:53:16 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h> // open
#include "libft.h" // ft_strncmp ft_malloc ft_strjoin ft_strlen
#include <unistd.h> // read write
#include <stdlib.h> // free
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

// in heredoc auch expanden
int	ft_heredoc(t_koopa *shell, t_data *data)
{
	char	*input;

	// handel_signals here
	shell->in = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			printf("ERROR\n");
			break ;
		}
		if (ft_strncmp(input, data->cmd_name, ft_strlen(data->cmd_name) == 0))
			break ;
		write(shell->in, input, ft_strlen(input));
		free(input);
	}
	close(shell->in);
	free(input);
	shell->in = open("heredoc", O_RDONLY);
	dup2(shell->in, STDIN_FILENO);
	close(shell->in);
	return (0);
}
