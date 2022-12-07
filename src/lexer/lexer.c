#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"

char **tokenizer(char *str)
{
	int i;
	char **tokens;

	i = 0;
	tokens = malloc(sizeof(char) * (token_count(str) + 1));
	// while (str[i])
	// {

	// }
	return (tokens);
}

