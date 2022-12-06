#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/Users/jschneid/42_Projects/minishell/42_minishell/includes/minishell.h"

void skip_str(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '!' && str[*i] <= '~')
		(*i)++;
}

void skip_whitespace(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
}

void skip_nbrs(char *str, int *i, int *counter)
{
	(*counter)++;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
}

void skip_qoutes(char *str, int *i, int *counter)
{
	(*counter)++;
	if (str[*i] == '"' || str[*i] == '\'')
		(*i)++;
}

void skip_flags(char *str, int *i, int *counter)
{
	(*counter)++;
	i++;
	skip_str(str, i, counter);
}

// static int token_count(char *str)
// {
// 	int	i;
// 	int count;

// 	i = 0;
// 	count = 0;
// 	while (str[i] != '\0')
// 	{
// 		printf("Start: c[%d]= %c\n", i, str[i]);
// 		if (str[i] == ' ')
// 		{
// 			printf("a\n");
// 			while (str[i] <= '!' && str[i] >= '~'&& str[i] != '\0')
// 				i++;
// 		}
// 		else if (str[i] == '"' || str[i] == '\'')
// 		{
// 			printf("b\n");
// 			count++;
// 			i++;
// 			while (str[i] != '"' && str[i] != '\'' && str[i] != '\0')
// 				i++;
// 		}
// 		else if (str[i] == '|' || str[i] == '<' || str[i] == '>')
// 		{
// 			printf("c\n");
// 			count++;
// 		}
// 		else if (str[i] >= '0' && str[i] <= '9')
// 		{
// 			printf("d\n");
// 			count++;
// 			while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
// 				i++;
// 		}
// 		else if (str[i] >= 'A' && str[i] <= 'z')
// 		{
// 			printf("e\n");
// 			count++;
// 			while (str[i] >= '!' && str[i] <= '~' && str[i] != '\0')
// 				i++;
// 		}
// 		else if (str[i] == '-')
// 		{
// 			printf("f\n");
// 			count++;
// 			i++;
// 			while (str[i] >= '!' && str[i] <= '~' && str[i] != '\0')
// 			{
// 				// printf("%c\n", str[i]);
// 				skip_str(&str[i], &i, &count);
// 				i++;
// 			}
// 		}
// 		if (str[i] != '\0')
// 			i++;
// 		printf("End: c[%d]= %c\n", i, str[i]);
// 	}
// 	printf("count: %d\n", count);
// 	return (count);
// }

static int token_count(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			skip_whitespace(str, &i, &count);
		else if (str[i] == '-')
			skip_flags(str, &i, &count);
		else if (str[i] == '"' || str[i] == '\'')
			skip_qoutes(str, &i, &count);
		else if (str[i] >= '0' && str[i] <= '9')
			skip_nbrs(str, &i, &count);
		else if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z'))
			skip_str(str, &i, &count);
		else if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			count++;
		printf("c[%d] = %c count: %d\n", i, str[i], count);
		if (str[i] != '\0')
			i++;
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

// size_t ft_strspn(const char *str, const char *accept)
// {
// 	size_t count;
// 	const char *p;

// 	count = 0;
// 	p = str;
// 	while(*p)
// 	{
// 		if (ft_strchr(accept, *p) == NULL)
// 			return (count);
// 		count++;
// 		p++;
// 	}
// 	return count;
// }

// size_t ft_strcspn(const char *str, const char *reject)
// {
// 	size_t count = 0;
// 	const char *p;

// 	p = str;
// 	while(*p)
// 	{
// 		if (ft_strchr(reject, *p) != NULL)
// 			return (count);
// 		count++;
// 		p++;
// 	}
// 	return count;
// }

// int nbr_of_tokens(char *str)
// {
// 	int nbr = 0;

// 	char *p = str;
// 	while (*p)
// 	{
// 		printf("%c\n", *p);
// 		if (*p == 34 || *p == 39)
// 		{
// 			p++;
// 			nbr++;
// 			while (*p != 34 &&  *p != 39)
// 			{
// 				printf("chille hier\n");
// 				p++;
// 			}
// 		}
// 		else if (*p == '>' || *p == '<' || *p == '|')
// 		{
// 			nbr++;
// 			p++;
// 		}
// 		else if (*p == ' ')
// 		{
// 			while (*p == ' ' && *p != '\0')
// 				p++;
// 		}
// 		else
// 		{
// 			while (*p > 'A' && *p < 'z')
// 				p++;
// 		}
// 		printf("%c\n", *p);
// 	}
// 	printf("nbr of tokens: %d\n", nbr);
// 	return nbr;
// }
