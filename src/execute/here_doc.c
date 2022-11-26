/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:39 by dgross            #+#    #+#             */
/*   Updated: 2022/11/26 15:29:21 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h> // open
#include "libft.h" // ft_strncmp ft_malloc ft_strjoin ft_strlen
#include <unistd.h> // read write
#include <stdlib.h> // free

// wird bearbeitet sobald wir wissen wo wir here_doc machen
void here_doc(t_koopa *shell)
{
	char	*input;
	int		length;
	int		limit_len;
	int		i;

	i = 0;
	
	shell->limiter = ft_strjoin(shell->limiter, "\n");
	limit_len = ft_strlen(shell->limiter);
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

void	check_heredoc(t_koopa *shell, int argc, char **argv)
{
	if (shell->here_doc == 1)
	{
		if (argc < 6)
		{
			throw_error("Wrong input: ./shell here_doc limiter \
			cmd1 cmd2 ... outfile");
		}
		shell->outfile = open(argv[argc - 1], O_CREAT | O_RDWR \
		| O_APPEND, 0777);
		if (shell->outfile == -1)
			throw_error("Wrong input: outfile Error");
		shell->limiter = argv[2];
		ft_here_doc(shell);
	}
	else
	{
		shell->infile = open(argv[1], O_RDONLY);
		if (shell->infile == -1)
			throw_error3("Wrong input: infile Error");
		shell->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (shell->outfile == -1)
			throw_error("Wrong input: outfile Error");
		shell->here_doc = 0;
	}
}
