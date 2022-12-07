#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/Users/jschneid/42_Projects/minishell/42_minishell/includes/minishell.h"

// ./ muss auch abgefangen werden --> endlos loop

static void skip_str(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '!' && str[*i] <= '~' && str[*i] != '\0')
		(*i)++;
	printf("%d--skip_str\n", *counter);
}

static void skip_whitespace(char *str, int *i)
{
 	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	printf("skip_whitespace\n");
}

static void skip_nbrs(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	printf("%d--skip_nbrs\n", *counter);
}

static void skip_sqoutes(char *str, int *i, int *counter)
{
	(*counter)++;
	(*i)++;
	while (str[*i] != 39 && str[*i] != '\0')
	{
		printf("str[%d] = %c\n", (*i), str[*i]);
		(*i)++;
	}
	printf("str[%d] = %c\n", (*i), str[*i]);
	if (str[*i + 1] == 39)
	{
		(*i)++;
		printf("%d--skip_sqoutes\n", *counter);
		return ;
	}
	if (str[*i + 1] != ' ')
	{
		while (str[*i] >= '!' && str[*i] <= '~' && str[*i] != '\0')
		(*i)++;
	}
	else
		(*i)++;
	printf("%d--skip_sqoutes\n", *counter);
}

static void skip_dqoutes(char *str, int *i, int *counter)
{
	(*counter)++;
	(*i)++;
	while (str[*i] != '"' && str[*i] != '\0')
	{
		printf("str[%d] = %c\n", (*i), str[*i]);
		(*i)++;
	}
	printf("str[%d] = %c\n", (*i), str[*i]);
	if (str[*i + 1] == '"')
	{
		(*i)++;
		printf("%d--skip_sqoutes\n", *counter);
		return ;
	}
	if (str[*i + 1] != ' ')
	{
		while (str[*i] >= '!' && str[*i] <= '~' && str[*i] != '\0')
		(*i)++;
	}
	else
		(*i)++;
	printf("%d--skip_dqoutes\n", *counter);
}

static void skip_flags(char *str, int *i, int *counter)
{
	(*counter)++;
	(*i)++;
	while (((str[*i] >= 'a' && str[*i] <= 'z')
			|| (str[*i] >= 'A' && str[*i] <= 'Z'))
			&&str[*i] != '\0')
	{
		if (str[*i + 1] == '"' || str[*i + 1] == 39)
		{
			(*i) += 2;
			while (str[*i] != '"' && str[*i] != '\0')
			{
				printf("str[%d] = %c\n", (*i), str[*i]);
				(*i)++;
			}
			(*i)++;
		}
		(*i)++;
	}
	printf("%d--skip_flags\n", *counter);
}

static void skip_opperator(int *i, int *counter)
{
	(*i)++;
	(*counter)++;
	printf("%d--skip_operator\n", *counter);
}

// Qoutes in einer funktion zusammen fassen
static int token_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		printf("istr[%d] = %c\n", i, str[i]);
		if (str[i] == ' ')
			skip_whitespace(str, &i);
		else if (str[i] == '-')
			skip_flags(str, &i, &count);
		else if (str[i] == 39)
			skip_sqoutes(str, &i, &count);
		else if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			skip_opperator(&i, &count);
		else if (str[i] == '"')
			skip_dqoutes(str, &i, &count);
		else if (str[i] >= '0' && str[i] <= '9')
			skip_nbrs(str, &i, &count);
		else if (str[i] >= '!' && str[i] <= '~')
			skip_str(str, &i, &count);
	}
	printf("count: %d\n", count);
	return (count);
}

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

