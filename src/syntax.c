/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:39:14 by dgross            #+#    #+#             */
/*   Updated: 2023/02/21 09:37:10 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <stdio.h>

void	choose_error(int error_code)
{
	if (error_code == 1)
		print_error("syntax error", NULL, "invalid redirection");
	if (error_code == 2)
		print_error("syntax error", NULL, "invalid pipe");
	g_exit_status = 258;
}

int	catch_one(char **token_arr, int arr_len)
{
	int	i;

	i = 0;
	if (arr_len == 1 && (token_arr[i][0] != '|' || token_arr[i][0] != '<'
		|| token_arr[i][0] != '>'))
		return (0);
	if (arr_len < 2 && (token_arr[i][0] == '|' || token_arr[i][0] == '<'
		|| token_arr[i][0] == '>' || ((token_arr[i + 1][0] == '<'
		&& token_arr[i + 1][1] == '<'))
		|| ((token_arr[i + 1][0] == '>' && token_arr[i + 1][1] == '>'))))
		return (1);
	if (arr_len < 2 && (token_arr[0][0] == '|'
		|| token_arr[arr_len - 1][0] == '|'))
		return (2);
	return (0);
}

int	catch_two(char **token_arr, int i)
{
	while (token_arr[i] != NULL)
	{
		if (token_arr[i][0] == '<' || token_arr[i][0] == '>')
		{
			if (token_arr[i - 1][0] == '>' || token_arr[i - 1][0] == '<')
				return (1);
		}
		if (token_arr[i][0] == '|')
		{
			if (token_arr[i - 1][0] == '>' || token_arr[i - 1][0] == '<'
				|| token_arr[i - 1][0] == '|')
				return (2);
		}
		i++;
	}
	if (token_arr[i] == NULL)
	{
		if (token_arr[i - 1][0] == '>' || token_arr[i - 1][0] == '<')
			return (1);
		if (token_arr[i - 1][0] == '|')
			return (2);
	}
	return (0);
}

int	syntax_check(char **token_arr)
{
	int	i;
	int	arr_len;
	int	flag;

	i = 1;
	flag = 0;
	arr_len = ft_ptrcnt(token_arr);
	if (arr_len == 0)
		return (0);
	flag = catch_one(token_arr, arr_len);
	if (flag > 0)
	{
		choose_error(flag);
		free_double(token_arr);
		return (1);
	}
	flag = catch_two(token_arr, i);
	if (flag > 0)
	{
		choose_error(flag);
		free_double(token_arr);
		return (1);
	}
	return (0);
}
