/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:39 by dgross            #+#    #+#             */
/*   Updated: 2022/12/10 15:47:23 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h> // open
#include "libft.h" // ft_strncmp ft_malloc ft_strjoin ft_strlen
#include <unistd.h> // read write
#include <stdlib.h> // free

// wird bearbeitet sobald wir wissen wo wir here_doc machen
static void	exec_heredoc(t_koopa *shell)
{
	shell->infile = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	while (1)
	{
		// gucken ob wir das irgendwie mit readline machen
		// read mit max malloc len ist nicht so schlau
		// zudem auch nur > printen nicht here_doc etc
		write(shell->infile, input, ft_strlen(input));
	}
	close(shell->infile);
	shell->infile = open("here_doc", O_RDONLY);
	free(shell->limiter);
	free(input);
}

// in heredoc auch expanden
int ft_heredoc(t_koopa *shell, t_data *data)
{
	// handel_signals here
	shell->infile = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	while (1)
	{
		
	}
	close(shell->infile);
	shell->infile = open("here_doc", O_RDONLY);
	return (0);	
}