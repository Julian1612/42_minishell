/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:51:45 by jschneid          #+#    #+#             */
/*   Updated: 2023/02/21 09:27:16 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	**tokenizer(char *str)
{
	char	**token_arr;
	int		token_count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	token_count = token_counter(str);
	token_arr = (char **) malloc(sizeof(char *) * (token_count + 1));
	if (token_arr == NULL)
		return (NULL);
	while (i < token_count)
	{
		if (init_arr(token_arr, str, &j, &i) == 1)
			return (NULL);
		i++;
	}
	free(str);
	token_arr[token_count] = NULL;
	return (token_arr);
}

int	token_counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			skip_whitespace(str, &i);
		else if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			skip_operator(str, &i, &count);
		else if (str[i] == '\'' || str[i] == '\"')
			skip_qoutes(str, &i, &count);
		else if (str[i] >= '0' && str[i] <= '9')
			skip_nbrs(str, &i, &count);
		else if ((str[i] >= '!' && str[i] <= '~') || (!ft_isascii(str[i])))
			skip_str(str, &i, &count);
	}
	return (count);
}

int	init_arr(char **token_arr, char *str, int *j, int *i)
{
	int	token_len;
	int	start_copy;

	start_copy = *j;
	token_len = get_token_length(str, j);
	if (token_len == -1)
		return (1);
	token_arr[*i] = (char *) malloc(sizeof(char) * (token_len + 1));
	if (token_arr[*i] == NULL)
		return (1);
	skip_whitespace(str, &start_copy);
	cpy_token(str, token_arr[*i], token_len, start_copy);
	token_arr[*i][token_len] = '\0';
	return (0);
}

int	get_token_length(char *str, int *j)
{
	int	token_len;

	token_len = 0;
	while (str[*j] != '\0')
	{
		if (ft_isspace(str[*j]))
			skip_whitespace(str, j);
		else if (str[*j] == '|' || str[*j] == '<' || str[*j] == '>')
			return (opp_len_counter(str, j));
		else if (str[*j] == '\"' || str[*j] == '\'')
			return (quote_len_counter(str, j));
		else if (str[*j] >= '0' && str[*j] <= '9')
			return (nbr_len_counter(str, j));
		else if ((str[*j] >= '!' && str[*j] <= '~') || (!ft_isascii(str[*j])))
			return (str_len_counter(str, j));
	}
	if (str[*j] == '\0')
		return (token_len);
	else
		return (-1);
}

void	cpy_token(char *str, char *token_arr, int token_len, int start_copy)
{
	int	i;

	i = 0;
	while (i < token_len)
	{
		token_arr[i] = str[start_copy];
		i++;
		start_copy++;
	}
}
