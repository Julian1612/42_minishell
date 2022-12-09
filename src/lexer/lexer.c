#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"

void counter_dqoute_len(char *str, int *j, int *token_len);
void counter_quote_len(char *str, int *j, int *token_len);

void count_str_len(char *str, int *j, int *token_len)
{
	while ((str[*j] >= '!' && str[*j] <= '~') && str[*j] != '\0')
	{
		(*j)++;
		(*token_len)++;
	}
}

void counter_flag_len(char *str, int *j, int *token_len)
{
	(*j)++;
	(*token_len)++;
	while (((str[*j] >= 'a' && str[*j] <= 'z')
			|| (str[*j] >= 'A' && str[*j] <= 'Z'))
			&&str[*j] != '\0')
	{
		if (str[*j + 1] == '"' || str[*j + 1] == 39)
		{
			(*j) += 2;
			while (str[*j] != '"' && str[*j] != '\0')
			{
				// printf("str[%d] = %c\n", (*i), str[*i]);
				(*j)++;
			}
			(*j)++;
		}
		(*j)++;
		(*token_len)++;
	}
}

int	get_token_length(char *str, int *j)
{
	int token_len;

	token_len = 0;
	while (str[*j] != '\0')
	{
		if (str[*j] == ' ')
			skip_whitespace(str, j);
		else if (str[*j] == '"')
		{
			counter_quote_len(str, j, &token_len);
			return (token_len);
		}
		else if (str[*j] == '-')
		{
			counter_flag_len(str, j, &token_len);
			return (token_len);
		}
		else if (str[*j] >= '!' && str[*j] <= '~')
		{
			count_str_len(str, j, &token_len);
			return (token_len);
		}
	}
	if (str[*j] == '\0')
			return (token_len);
	else
		return (-1);
}

void cpy_token(char *str, char *token_arr, int token_len, int start_copy)
{
	int i;

	i = 0;
	while (i < token_len)
	{
		token_arr[i] = str[start_copy];
		i++;
		start_copy++;
	}
}

void counter_dqoutes_len(char *str, int *j, int *token_len)
{
	if (str[*j] == '"' && str[*j + 1] == '"')
	{
		(*j) += 2;
		return ;
	}
	(*token_len)++;
	(*j)++;
	while (str[*j] != '"' && str[*j] != '\0')
	{
		(*token_len)++;
		(*j)++;
	}
	if (str[*j + 1] == '"')
	{
		(*token_len)++;
		(*j)++;
		return ;
	}
	if (str[*j + 1] != ' ')
	{
		while (str[*j] >= '!' && str[*j] <= '~' && str[*j] != '\0')
		{
			(*token_len)++;
			(*j)++;
		}
	}
	else
	{
		(*token_len)++;
		(*j)++;
	}
}

void	counter_sqoutes_len(char *str, int *j, int *token_len)
{
	if (str[*j] == 39 && str[*j + 1] == 39)
	{
		(*j) += 2;
		return ;
	}
	(*token_len)++;
	(*j)++;
	while (str[*j] != 39 && str[*j] != '\0')
	{
		(*token_len)++;
		(*j)++;
		printf("str[%d] = %c\n", (*j), str[*j]);
	}
	if (str[*j + 1] == 39)
	{
		(*token_len)++;
		(*j)++;
		return ;
	}
	if (str[*j + 1] != ' ')
	{
		while (str[*j] >= '!' && str[*j] <= '~' && str[*j] != '\0')
		{
			(*token_len)++;
			(*j)++;
		}
	}
	else
	{
		(*token_len)++;
		(*j)++;
	}
}

void counter_quote_len(char *str, int *j, int *token_len)
{
	if (str[*j] == 39)
		counter_sqoutes_len(str, j, token_len);
	else if (str[*j] == '"')
		counter_dqoutes_len(str, j, token_len);
}

int tokenizer(char *str)
{
	char	**token_arr;
	int		token_count;
	int		token_len;
	int		i;
	int		j;
	int		start_copy;

	token_count = token_counter(str);
	printf("token_count = %d\n", token_count);
	token_arr = (char **) malloc(sizeof(char *) * (token_count + 1));
	if (token_arr == NULL)
	{
		perror("minishell: malloc failed\n");
		return (1);
	}
	i = 0;
	j = 0;
	while (i < token_count)
	{
		start_copy = j;
		token_len = get_token_length(str, &j);
		if (token_len == -1)
		{
			printf("hier\n");
			return (1);
		}
		token_arr[i] = (char *) malloc(sizeof(char) * token_len + 1);
		if (token_arr[i] == NULL)
		{
			perror("minishell: malloc failed\n");
			return (1);
		}
		skip_whitespace(str, &start_copy);
		printf("start_cpy = %d\n", start_copy);
		printf("toke_length = %d\n", token_len);
		// Hier muss dann der token erstellt werden in einer funktion
		cpy_token(str, token_arr[i], token_len, start_copy);
		token_arr[i][token_len] = '\0';
		i++;
	}
	token_arr[token_count] = NULL;
	// Test ///
	i = 0;
	while (token_arr[i] != NULL)
	{
		printf("token_arr[%d] = %s\n", i, token_arr[i]);
		i++;
	}
	// Test ///
	return (0);
}
