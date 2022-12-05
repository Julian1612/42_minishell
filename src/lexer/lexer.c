#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/Users/jschneid/42_Projects/minishell/42_minishell/includes/minishell.h"

size_t ft_strspn(const char *str, const char *accept)
{
	size_t count;
	const char *p;

	count = 0;
	p = str;
	while(*p)
	{
		if (ft_strchr(accept, *p) == NULL)
			return (count);
		count++;
		p++;
	}
	return count;
}

size_t ft_strcspn(const char *str, const char *reject)
{
	size_t count = 0;
	const char *p;

	p = str;
	while(*p)
	{
		if (ft_strchr(reject, *p) != NULL)
			return (count);
		count++;
		p++;
	}
	return count;
}

int nbr_of_tokens(char *str)
{
	int nbr = 0;

	char *p = str;
	while (*p)
	{
		printf("%c\n", *p);
		if (*p == 34 || *p == 39)
		{
			p++;
			nbr++;
			while (*p != 34 && *p != 39)
			{
				printf("chille hier\n");
				p++;
			}
		}
		else if (*p == '>' || *p == '<' || *p == '|')
		{
			nbr++;
			p++;
		}
		else if (*p == ' ')
		{
			while (*p == ' ' && *p != '\0')
				p++;
		}
		else
		{
			while (*p > 'A' && *p < 'z')
				p++;
		}
		printf("%c\n", *p);
	}
	printf("nbr of tokens: %d\n", nbr);
	return nbr;
}

char **tokenizer(char *str)
{
	int i;
	char **tokens;

	i = 0;
	tokens = malloc(sizeof(char *) * (nbr_of_tokens(str) + 1));
	// while (str[i])
	// {

	// }
	return (tokens);
}

// int main()
// {
// 	char *teststr = "cat example.txt | grep "hello" | wc -l";
// 	tokenizer(teststr);
// }
