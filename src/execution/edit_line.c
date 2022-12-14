/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:00:51 by dgross            #+#    #+#             */
/*   Updated: 2022/12/14 18:45:12 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
char	*double_to_str(t_data *data)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_calloc(1, sizeof(char));
	while (data->cmd_line[++i] != NULL)
	{
		str = ft_strjoin(str, data->cmd_line[i]);
		str = ft_strjoin(str, "\n");
	}
	return (str);
}

int	init_exp(t_exp *exp, t_data *data)
{
	if (data->operator == PIPE || data->operator == CMD)
	{
		exp->line = double_to_str(data);
		exp->squo = -1;
		exp->dquo = -1;
		exp->len = 0;
		return (0);
	}
	return (1);
}

int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' \
	|| c == '\t' || c == '\v' || c == ' '\
	|| c == '\'' || c == '\"');
}
