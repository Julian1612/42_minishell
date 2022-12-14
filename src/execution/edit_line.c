/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:00:51 by dgross            #+#    #+#             */
/*   Updated: 2023/01/09 18:57:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <stdlib.h> // free

char	*double_to_str(t_data *data)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	str = ft_strdup("");
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
	exp->line = double_to_str(data);
	exp->squo = -1;
	exp->dquo = -1;
	exp->len = 0;
	return (0);
}

char	*take_var_name(int i, int offset, t_exp *exp)
{
	char	*variable;

	variable = ft_substr(exp->line, (i + offset), exp->len);
	return (variable);
}

int	ft_is_end(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' \
	|| c == '\t' || c == '\v' || c == ' '\
	|| c == '\'' || c == '\"' || c == '\0' || c == '/');
}

int	replace(t_data *data, t_exp *exp)
{
	free_double(data->cmd_line);
	data->cmd_line = NULL;
	data->cmd_line = ft_split(exp->line, '\n');
	if (data->cmd_line == NULL)
	{
		print_error("cmd_line", NULL, "Not enough space/cannot \
		allocate memory");
		return (ERROR);
	}
	free(exp->line);
	if (exp->dquo == TRUE || exp->squo == TRUE)
	{
		print_error("syntax error", NULL, "unclosed quotation mark");
		return (-1);
	}
	return (0);
}
