/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:39 by dgross            #+#    #+#             */
/*   Updated: 2022/11/26 13:53:58 by dgross           ###   ########.fr       */
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
	
	pipex->limiter = ft_strjoin(pipex->limiter, "\n");
	limit_len = ft_strlen(pipex->limiter);
	pipex->infile = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	while (1)
	{
		
		write(pipex->infile, input, ft_strlen(input));
	}
	close(pipex->infile);
	pipex->infile = open("here_doc", O_RDONLY);
	free(pipex->limiter);
	free(input);
}

void	check_heredoc(t_koopa *shell, int argc, char **argv)
{
	if (pipex->here_doc == 1)
	{
		if (argc < 6)
		{
			throw_error("Wrong input: ./pipex here_doc limiter \
			cmd1 cmd2 ... outfile");
		}
		pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR \
		| O_APPEND, 0777);
		if (pipex->outfile == -1)
			throw_error("Wrong input: outfile Error");
		pipex->limiter = argv[2];
		ft_here_doc(pipex);
	}
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
			throw_error3("Wrong input: infile Error");
		pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (pipex->outfile == -1)
			throw_error("Wrong input: outfile Error");
		pipex->here_doc = 0;
	}
}
