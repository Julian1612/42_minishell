/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:52 by dgross            #+#    #+#             */
/*   Updated: 2022/12/30 20:11:02 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

static void	remove_quots(t_exp *exp, int count)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = ft_calloc(count + 1, sizeof(char));
	while (exp->line[++i] != '\0')
	{
		if (exp->line[i] == '\'')
			while (exp->line[++i] != '\0' && exp->line[i] != '\'')
				tmp[j++] = exp->line[i];
		else if (exp->line[i] == '\"')
			while (exp->line[++i] != '\0' && exp->line[i] != '\"')
				tmp[j++] = exp->line[i];
		else
			tmp[j++] = exp->line[i];
	}
	tmp[j] = '\0';
	free(exp->line);
	exp->line = ft_strdup(tmp);
	free(tmp);
}

char	*get_variable(t_exp *exp, int *idx)
{
	int		i;
	char	*variable;

	exp->len = 0;
	i = *idx;
	while (exp->line[++i] != '\0' && !ft_isspace(exp->line[i]))
	{
		exp->len++;
		if (exp->line[i] == '?' || exp->line[i] == '$')
			break ;
	}
	i = *idx;
	variable = ft_substr(exp->line, ++i, exp->len);
	return (variable);
}

static char	*get_content(t_koopa *shell, t_exp *exp, int *idx)
{
	char	*variable;
	char	*content;

	variable = get_variable(exp, idx);
	if (ft_check_char(variable[0]))
	{
		free(variable);
		return (NULL);
	}
	content = ft_strdup(ft_name_len(variable) + ft_getenv(shell, variable));
	free(variable);
	exp->content_len = ft_strlen(content);
	return (content);
}

void	exec_expand(t_koopa *shell, t_exp *exp, int *idx, int *j)
{
	char	*content;
	char	*start_tmp;
	char	*mid_tmp;
	char	*end_tmp;

	exp->content_len = 0;
	content = get_content(shell, exp, idx);
	if (content == NULL)
		return ;
	start_tmp = ft_substr(exp->line, 0, *idx);
	mid_tmp = ft_strjoin(start_tmp, content);
	free(content);
	free(start_tmp);
	end_tmp = ft_substr(exp->line, *idx + exp->len + 1, ft_strlen(exp->line));
	free(exp->line);
	exp->line = ft_strjoin(mid_tmp, end_tmp);
	free(mid_tmp);
	free(end_tmp);
	*j += exp->content_len;
	*idx += exp->content_len - 1;
}

int	ft_expand(t_koopa *shell, t_data *data)
{
	t_exp	exp;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (init_exp(&exp, data) == 1)
		return (0);
	while (exp.line[++i] != '\0')
	{
		if (exp.line[i] == '\'' && exp.dquo == FALSE)
			exp.squo *= -1;
		else if (exp.line[i] == '\"' && exp.squo == FALSE)
			exp.dquo *= -1;
		else if (exp.line[i] == '$' && exp.squo != TRUE)
			exec_expand(shell, &exp, &i, &j);
		else
			j++;
	}
	remove_quots(&exp, j);
	replace(data, &exp);
	return (0);
}
