#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"

int	get_token_length(char *str, int *i)
{
	int token_length;

	token_length = 0;
	// Hier wird dann i immer weiter hoch gezählt um durch den string zu gehen
	// quasi um von string zu string zu springen
	// gleihzeitig muss in der function mit token_length gezaehlt werden
	// Aus der differenz von i und token_length kann dann die laenge des tokens
	// berechnet werden anschließend kann dann returned werden
	// und das token erstellt.
	printf("str[%d] = %c\n", (*i), str[*i]);

	return (token_length);
}

int create_token(char *token_arr, char *str, int *i)
{
	int j;
	int token_length;

	j = 0;
	// erst token len fertig machen
	token_length = get_token_length(str, i);
	token_arr = (char *) malloc(sizeof(char) * (token_length + 1));
	if (token_arr == NULL)
	{
		perror("minishell: malloc failed\n");
		return (1);
	}
	token_arr[token_length] = '\0';
	token_arr[0] = '1'; // delet when not used anymore
	// while (i < token_length)
	// {
	// 	token_arr[(*i)] = str[j];
	// 	(*i)++;
	// 	j++;
	// }
	return (0);
}

int tokenizer(char *str)
{
	int		i;
	int		num_tokens;
	char	**token_arr;

	i = 0;
	num_tokens = token_counter(str);
	token_arr = (char **) malloc(sizeof(char *) * ( + 1));
	if (token_arr == NULL)
	{
		perror("iminishell: malloc failed\n");
		return (1);
	}
	token_arr[num_tokens] = NULL;
	printf("num_tokens: %d\n", num_tokens);
	while (i < num_tokens - 1)
	{
		if(create_token(token_arr[i], str, &i))
		{
			free(token_arr);
			return (1);
		}
		i++;
	}
	return (0);
}

