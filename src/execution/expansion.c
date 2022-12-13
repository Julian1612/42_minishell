/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:52 by dgross            #+#    #+#             */
/*   Updated: 2022/12/13 13:33:38 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

static char	*get_variable(t_exp *exp, int *idx)
{
	int		i;
	int		len;
	int		j;
	char	*variable;

	i = *idx;
	j = -1;
	len = 0;
	while (exp->line[++i] != '\0' && !ft_isspace(exp->line[i]))
		len++;
	variable = ft_calloc(len + 1, sizeof(char));
	i = *idx;
	while (exp->line[++i] != '\0' && !ft_isspace(exp->line[i]))
		variable[++j] = exp->line[i];
	variable[++j] = '\0';
	return (variable);
}

static void	exec_expand(t_koopa *shell, t_exp *exp, int *idx)
{
	char	*variable;
	char	*content;
	char	*new_str;

	variable = get_variable(exp, idx);
	content = ft_getenv(shell, variable) + ft_name_len(variable);
	new_str = ft_substr();
	ft_strlen(content);
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
		if (exp.line[i] == '$' && exp.dquo == 1)
			exec_expand(shell, &exp, &i);
	}
	return (0);
}

//// echo $USER test "$USER '$USER' soos"