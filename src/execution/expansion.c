/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:52 by dgross            #+#    #+#             */
/*   Updated: 2023/02/21 09:52:55 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <stdio.h> // NULL
#include <stdlib.h> // free

static void	remove_quotes(t_exp *exp, int count)
{
	char	*tmp;
	char	typ;
	int		i;
	int		j;

	i = -1;
	j = 0;
	typ = 'X';
	tmp = ft_calloc(count + 1, sizeof(char));
	while (exp->line[++i] != '\0')
	{
		if (exp->line[i] == '\'' || exp->line[i] == '\"')
		{
			typ = exp->line[i];
			while (exp->line[++i] != '\0' && exp->line[i] != typ)
				tmp[j++] = exp->line[i];
		}
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
	int		offset;

	exp->len = 0;
	i = *idx;
	offset = 1;
	while (exp->line[++i] != '\0' && !ft_is_end(exp->line[i]))
	{
		if (exp->line[*idx + 1] == '?')
		{
			exp->len++;
			break ;
		}
		else if (!ft_isalnum(exp->line[*idx + 1]) && exp->line[*idx + 1] != '_')
		{
			--offset;
			break ;
		}
		else if (!ft_isalnum(exp->line[i]) && exp->line[i] != '_')
			break ;
		exp->len++;
	}
	i = *idx;
	return (take_var_name(i, offset, exp));
}

static char	*get_content(t_koopa *shell, t_exp *exp, int *idx)
{
	char	*variable;
	char	*content;

	variable = get_variable(exp, idx);
	variable = ft_addchar(variable, '=');
	if (variable[0] != '?' && !ft_isalnum(variable[0]) && variable[0] != '_')
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
	if (data->cmd_line == NULL)
		return (0);
	init_exp(&exp, data);
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
	remove_quotes(&exp, j);
	if (replace(data, &exp) == ERROR)
		return (ERROR);
	return (0);
}
