/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:52 by dgross            #+#    #+#             */
/*   Updated: 2022/12/11 18:53:22 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

// remove quots
// variable expansion
// tilde expansion
// substitution

static void	remove_quots(t_exp *exp)
{
	int	i;

	i = -1;
	while (exp->line[++i] != '\0')
	{
		if (exp->line[i] == 'd')
			;
	}
}

static char	*get_line(t_data *data)
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

static void	init_exp(t_exp *exp, t_data *data)
{
	exp->line = get_line(data);
	exp->quote_typ = -1;
	exp->expand = FALSE;
}

static int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' \
	|| c == '\t' || c == '\v' || c == ' '\
	|| c == '\'' || c == '\"');
}

static char	*get_content(char *variable)
{
	int		i;
	char	*content;

	i = 0;
	while (!ft_isspace(variable[i]))
		i++;
	content = ft_calloc(i, sizeof(char));
	if (content == NULL)
		return (NULL);
	i = 0;
	while (!ft_isspace(variable[++i]))
		content[i - 1] = variable[i];
	content[i] = '\0';
	return (content);
}

static char	*exec_expansion(t_koopa *shell, t_exp *exp)
{
	char	*variable;
	char	*content;
	char	*line;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	line = ft_calloc(10000, sizeof(char));
	if (!line)
		return (NULL);
	while (exp->line[++i] != '\0')
	{
		if (exp->line[i] == '\'')
		{
			line[k] = exp->line[i];
			i++;
			k++;
			while (exp->line[i] != '\'')
			{
				line[k] = exp->line[i];
				k++;
				i++;
			}
		}
		if (exp->line[i] == '$')
		{
			variable = get_content(&exp->line[i]);
			j = ft_name_len(variable);
			i += j;
			content = ft_getenv(shell, variable) + j;
			j = 0;
			while (content[j] != '\0')
			{
				line[k] = content[j];
				j++;
				k++;
			}
			j = 0;
		}
		line[k] = exp->line[i];
		k++;
	}
	line[k] = '\0';
	return (line);
}

int	ft_expand(t_koopa *shell, t_data *data)
{
	t_exp	exp;
	int		i;
	char	*str;

	i = 0;
	while (data != NULL)
	{
		init_exp(&exp, data);
		while (exp.line[++i] != '\0')
		{
			if (exp.line[i] == '\'' || exp.line[i] == '\"')
			{
				exp.quote_typ = exp.line[i];
				remove_quots(&exp);
			}
			if (exp.line[i] == '$' && exp.quote_typ != '\'')
				exp.expand = TRUE;
		}
		if (exp.expand == TRUE)
		{
			str = exec_expansion(shell, &exp);
			free(data->cmd_line);
			data->cmd_line = ft_split(str, '\n');
			exp.expand = false;
		}
		data = data->next;
	}
	return (0);
}
