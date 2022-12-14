/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:52 by dgross            #+#    #+#             */
/*   Updated: 2022/12/14 12:50:25 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

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
	char	*start;
	char	*mid;
	char	*end;

	variable = get_variable(exp, idx);
	content = ft_getenv(shell, variable) + ft_name_len(variable);
	start = ft_substr(exp->line, 0, *idx);
	mid = ft_strjoin(start, content);
	*idx += exp->len;
	end = ft_substr(exp->line, *idx + 1, ft_strlen(exp->line));
	free(exp->line);
	exp->line = ft_strjoin(mid, end);
}

int	ft_expand(t_koopa *shell, t_data *data)
{
	t_exp	exp;
	int		i;

	i = -1;
	init_exp(&exp, data);
	while (exp.line[++i] != '\0')
	{
		if (exp.line[i] == '\'' && exp.dquo < 0)
			exp.squo *= -1;
		if (exp.line[i] == '\"' && exp.squo < 0)
			exp.dquo *= -1;
		if (exp.line[i] == '$' && exp.squo != 1)
			exec_expand(shell, &exp, &i);
	}
	free_double(data->cmd_line);
	data->cmd_line = ft_split(exp.line, '\n');
	return (0);
}

// echo "$USER '$USER' $USER" '$USER'
// echo "dna