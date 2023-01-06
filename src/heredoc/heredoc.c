/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:15:39 by dgross            #+#    #+#             */
/*   Updated: 2023/01/06 10:44:37 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h> // open
#include <unistd.h> // write, close, dup2, dup
#include <stdlib.h> // free, malloc
#include <signal.h> // signal
#include <sys/stat.h> // fstat

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
	shell->in = open("here_doc", O_RDONLY, 00644);
}

static int	catch_crash(int fd, char *heredoc)
{
	struct stat	file_stat;

	if (fstat(STDIN_FILENO, &file_stat) != 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		free(heredoc);
		return (ERROR);
	}
	close(fd);
	return (0);
}

static char	*heredoc_strjoin(char *s1, char const *s2)
{
	char	*new_string;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (s1[0] == '\0' && s2[0] == '\0')
	len++;
	new_string = malloc (sizeof(char) * (len));
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s1, len);
	ft_strlcat(new_string, s2, len);
	free(s1);
	return (new_string);
}

int	ft_heredoc(t_koopa *shell, t_data *tabel)
{
	char	*input;
	char	*heredoc;
	int		i;
	int		fd;

	fd = 0;
	fd = dup(STDIN_FILENO);
	signal(SIGINT, ft_signal_heredoc);
	signal(SIGQUIT, SIG_IGN);
	heredoc = ft_strdup("");
	i = check_limiter(tabel);
	shell->in = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 00644);
	while (1)
	{
		input = readline("> ");
		if (!input || ft_strcmp(input, tabel->cmd_name) == 0)
			break ;
		heredoc = heredoc_strjoin(heredoc, input);
		heredoc = ft_addchar(heredoc, '\n');
		free(input);
	}
	if (catch_crash(fd, heredoc) == ERROR)
		return (ERROR);
	finish_heredoc(shell, heredoc, i);
	return (0);
}
