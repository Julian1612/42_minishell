#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"

void count_str_len(char *str, int *j, int *token_length)
{
	(*token_length)++;
	while ((str[*j] >= '!' && str[*j] <= '~') && str[*j] != '\0')
	{
		printf("istr[%d] = %c\n", (*j), str[*j]);
		(*j)++;
		(*token_length)++;
	}
}

void skip_whitespace(char *str, int *i)
{
 	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	// printf("skip_whitespace\n");
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
	if (str[*j] == ' ')
		skip_whitespace(str, j);
	if (str[*j] >= '!' && str[*j] <= '~')
	{
		count_str_len(str, j, &token_length);
		return (token_length);
	}
	printf("token_length = %d\n", token_length);
	return (-1);
}

int tokenizer(char *str)
{
	char	**token_arr;
	int		token_count;
	int		token_length;
	int		i;
	int		j;

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
		token_length = get_token_length(str, &j);
		token_arr[i] = (char *) malloc(sizeof(char) * token_length + 1);
		if (token_arr[i] == NULL)
		{
			perror("minishell: malloc failed\n");
			return (1);
		}
		// Hier muss dann der token erstellt werden in einer funktion
		// cpy_token();
		token_arr[i][token_length] = '\0';
		i++;
	}
	token_arr[token_count] = NULL;
	return (0);
}
