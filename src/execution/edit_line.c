/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:00:51 by dgross            #+#    #+#             */
/*   Updated: 2022/12/27 21:47:59 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h> // perror
#include <stdlib.h>

char	*double_to_str(t_data *data)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	str = ft_calloc(1, sizeof(char));
	while (data->cmd_line[++i] != NULL)
	{
		tmp = ft_strjoin(str, data->cmd_line[i]);
		free(str);
		str = ft_strjoin(tmp, "\n");
		free(tmp);
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

int	replace(t_data *data, t_exp *exp)
{
	free_double(data->cmd_line);
	data->cmd_line = ft_split(exp->line, '\n');
	if (data->cmd_line == NULL)
	{
		print_error("cmd_line", NULL, "Not enough space/cannot \
		allocate memory");
		return (ERROR);
	}
	free(exp->line);
	return (0);
}

int	ft_check_char(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' \
	|| c == '\t' || c == '\v' || c == ' ' || c == '$'\
	|| c == '\'' || c == '\"' || c == '\0');
}
