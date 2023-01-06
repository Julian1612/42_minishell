/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:47:29 by dna               #+#    #+#             */
/*   Updated: 2023/01/06 10:40:58 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <stdio.h> // NULL
#include <stdlib.h> // free 

static char	*ft_content(t_koopa *shell, t_exp *doc, int *idx)
{
	char	*variable;
	char	*content;

	variable = get_variable(doc, idx);
	if (ft_check_char(variable[0]))
	{
		free(variable);
		return (NULL);
	}
	content = ft_strdup(ft_name_len(variable) + ft_getenv(shell, variable));
	free(variable);
	doc->content_len = ft_strlen(content);
	return (content);
}

static void	execute_expansion(t_koopa *shell, t_exp *doc, int *i)
{
	char	*content;
	char	*start_tmp;
	char	*mid_tmp;
	char	*end_tmp;

	content = ft_content(shell, doc, i);
	if (content == NULL)
		return ;
	start_tmp = ft_substr(doc->line, 0, *i);
	mid_tmp = ft_strjoin(start_tmp, content);
	free(content);
	free(start_tmp);
	end_tmp = ft_substr(doc->line, *i + doc->len + 1, ft_strlen(doc->line));
	free(doc->line);
	doc->line = ft_strjoin(mid_tmp, end_tmp);
	free(mid_tmp);
	free(end_tmp);
	*i += doc->content_len - 1;
}

static int	init_doc(t_exp	*doc, char *heredoc)
{
	if (heredoc == NULL)
		return (1);
	doc->line = ft_strdup(heredoc);
	free(heredoc);
	doc->squo = -1;
	doc->dquo = -1;
	doc->len = 0;
	return (0);
}

char	*ft_expand_heredoc(t_koopa *shell, char *heredoc)
{
	t_exp	doc;
	int		i;

	i = -1;
	if (init_doc(&doc, heredoc) == 1)
		return (NULL);
	while (doc.line[++i] != '\0')
		if (doc.line[i] == '$')
			execute_expansion(shell, &doc, &i);
	return (doc.line);
}
