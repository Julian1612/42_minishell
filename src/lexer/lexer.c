#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/Users/jschneid/42_Projects/minishell/42_minishell/includes/minishell.h"

#include <stdio.h>
#include <string.h>
size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	i;
	int		b;
	int		j;

	j = 0;
	i = c;
	b = ft_strlen(s);
	while (j <= b)
	{
		if (s[j] == i)
			return ((char *)s + j);
		j++;
	}
	return (NULL);
}

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
	if (ft_strchr("<>|", *p) != NULL)
	{
		nbr++;
		p++;
	}
	else if (*p == ' ')
	{
		p += ft_strspn(p, " ");
	}
	else
	{
		nbr++;
		p += ft_strcspn(p, "<>| ");
	}
	}
	printf("nbr of tokens: %d", nbr);
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
