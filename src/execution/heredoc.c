/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:39 by dgross            #+#    #+#             */
/*   Updated: 2022/12/30 18:51:56 by dgross           ###   ########.fr       */
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
#include <signal.h>
#include <errno.h>

static int	check_limiter(t_data *tabel)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strdup("");
	while (tabel->cmd_name[++i] != '\0')
	{
		if (tabel->cmd_name[i] == '\'')
			while (tabel->cmd_name[++i] != '\0' && tabel->cmd_name[i] != '\'')
				tmp = ft_addchar(tmp, tabel->cmd_name[i]);
		else if (tabel->cmd_name[i] == '\"')
			while (tabel->cmd_name[++i] != '\0' && tabel->cmd_name[i] != '\"')
				tmp = ft_addchar(tmp, tabel->cmd_name[i]);
		else
			tmp = ft_addchar(tmp, tabel->cmd_name[i]);
	}
	i = ft_strcmp(tabel->cmd_name, tmp);
	free(tabel->cmd_name);
	tabel->cmd_name = ft_strdup(tmp);
	free(tmp);
	return (i);
}

static void	finish_heredoc(t_koopa *shell, char	*heredoc, int i)
{
	if (i == 0)
		heredoc = ft_expand_heredoc(shell, heredoc);
	write(shell->in, heredoc, ft_strlen(heredoc));
	close(shell->in);
	free(heredoc);
	shell->in = open("here_doc", O_RDONLY);
	dup2(shell->in, STDIN_FILENO);
	close(shell->in);
}

static int	catch_crash(int fd, char *heredoc)
{
	int	test;

	test = dup(STDIN_FILENO);
	if (test < 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		free(heredoc);
		return (ERROR);
	}
	close(fd);
	close(test);
	return (0);
}

int	check_for_heredoc(t_koopa *shell, t_data *tabel)
{
	shell->tmp_stdin = dup(STDIN_FILENO);
	shell->tmp_stdout = dup(STDOUT_FILENO);
	while (tabel != NULL)
	{
		if (tabel->operator == HEREDOC)
			if (ft_heredoc(shell, tabel) == ERROR)
				return (ERROR);
		tabel = tabel->next;
	}
	return (0);
}

int	ft_heredoc(t_koopa *shell, t_data *tabel)
{
	char	*input;
	char	*heredoc;
	int		i;
	int		fd;

	fd = dup(STDIN_FILENO);
	signal(SIGINT, ft_signal_heredoc);
	signal(SIGQUIT, SIG_IGN);
	heredoc = ft_strdup("");
	i = check_limiter(tabel);
	shell->in = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	while (1)
	{
		input = readline("> ");
		if (!input || ft_strncmp(input, tabel->cmd_name, \
		ft_strlen(tabel->cmd_name)) == 0)
			break ;
		heredoc = ft_strjoin(heredoc, input);
		heredoc = ft_strjoin(heredoc, "\n");
		free(input);
	}
	if (catch_crash(fd, heredoc) == ERROR)
		return (ERROR);
	finish_heredoc(shell, heredoc, i);
	return (0);
}
