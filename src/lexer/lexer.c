#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"

void count_str_len(char *str, int *j, int *token_length)
{
	while ((str[*j] >= '!' && str[*j] <= '~') && str[*j] != '\0')
	{
		(*j)++;
		(*token_length)++;
	}
}

// Hier wird dann i immer weiter hoch gezählt um durch den string zu gehen
// quasi um von string zu string zu springen
// gleihzeitig muss in der function mit token_length gezaehlt werden
// Aus der differenz von i und token_length kann dann die laenge des tokens
// berechnet werden anschließend kann dann returned werden
// und das token erstellt.
int	get_token_length(char *str, int *j)
{
	int token_length;

	token_length = 0;
	while (str[*j] != '\0')
	{
		if (str[*j] == ' ')
			skip_whitespace(str, j);
		else if (str[*j] >= '!' && str[*j] <= '~')
		{
			count_str_len(str, j, &token_length);
			return (token_length);
		}
	}
	return (-1);
}

void cpy_token(char *str, char *token_arr, int token_length, int start_copy)
{
	int i;

	i = 0;
	while (i < token_length)
	{
		token_arr[i] = str[start_copy];
		i++;
		start_copy++;
	}
}

int tokenizer(char *str)
{
	char	**token_arr;
	int		token_count;
	int		token_length;
	int		i;
	int		j;
	int		start_copy;

	token_count = token_counter(str);
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
		token_length = get_token_length(str, &j);
		if (token_length == -1)
			return (1);
		printf("token_length = %d\n", token_length);
		token_arr[i] = (char *) malloc(sizeof(char) * token_length + 1);
		if (token_arr[i] == NULL)
		{
			perror("minishell: malloc failed\n");
			return (1);
		}
		skip_whitespace(str, &start_copy);
		printf("start_cpy = %d\n", start_copy);
		// Hier muss dann der token erstellt werden in einer funktion
		cpy_token(str, token_arr[i], token_length, start_copy);
		token_arr[i][token_length] = '\0';
		i++;
	}
	// Test ///
	i = 0;
	while (token_arr[i] != NULL)
	{
		printf("token_arr[%d] = %s\n", i, token_arr[i]);
		i++;
	}
	// Test ///
	token_arr[token_count] = NULL;
	return (0);
}
