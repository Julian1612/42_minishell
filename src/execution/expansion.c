/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:52 by dgross            #+#    #+#             */
/*   Updated: 2022/12/14 18:38:12 by dgross           ###   ########.fr       */
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

	i = 0;
	j = 0;
	tmp = ft_calloc(count, sizeof(char));
	while (exp->line[i++] != '\0')
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

static char	*get_variable(t_exp *exp, int *idx)
{
	int		i;
	char	*variable;

	exp->len = 0;
	i = *idx;
	while (exp->line[++i] != '\0' && !ft_isspace(exp->line[i]))
		exp->len++;
	i = *idx;
	variable = ft_substr(exp->line, ++i, exp->len);
	return (variable);
}

static void	exec_expand(t_koopa *shell, t_exp *exp, int *idx)
{
	char	*variable;
	char	*content;
	char	*start_tmp;
	char	*mid_tmp;
	char	*end_tmp;

	variable = get_variable(exp, idx);
	content = ft_getenv(shell, variable) + ft_name_len(variable);
	start_tmp = ft_substr(exp->line, 0, *idx);
	mid_tmp = ft_strjoin(start_tmp, content);
	*idx += exp->len;
	end_tmp = ft_substr(exp->line, *idx + 1, ft_strlen(exp->line));
	free(exp->line);
	exp->line = ft_strjoin(mid_tmp, end_tmp);
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
		if (exp.line[i] == '\'' && exp.dquo < 0)
			exp.squo *= -1;
		else if (exp.line[i] == '\"' && exp.squo < 0)
			exp.dquo *= -1;
		else if (exp.line[i] == '$' && exp.squo != 1)
		{
			exec_expand(shell, &exp, &i);
			j += exp.len - 1;
		}
		else
			j++;
	}
	remove_quots(&exp, j);
	free_double(data->cmd_line);
	data->cmd_line = ft_split(exp.line, '\n');
	return (0);
}
