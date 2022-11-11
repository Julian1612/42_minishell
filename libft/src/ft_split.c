/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:46:55 by dgross            #+#    #+#             */
/*   Updated: 2022/05/03 17:25:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // free malloc

static size_t	ft_strcounter(char const *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}

static char	*ft_allocwords(char const *str, char c)
{
	char	*pointer;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	pointer = malloc (sizeof(char) * (i + 1));
	if (pointer == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != c)
	{
		pointer[i] = str[i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}

static char	**ft_freestr(char **str, size_t i)
{
	while (i)
	{
		free (str[i]);
		i--;
	}
	free (str);
	return (NULL);
}

static char	*ft_tester(char **new_str, size_t i, char const *s, char c)
{
	new_str[i] = ft_allocwords(s, c);
	if (new_str[i] == NULL)
	{
		ft_freestr(new_str, i + 1);
		return (NULL);
	}
	return (new_str[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	len;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strcounter(s, c);
	new_str = malloc(sizeof(char *) * (len + 1));
	while (*s && new_str)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (ft_tester(new_str, i, s, c) == NULL)
				return (NULL);
			i++;
		}
		while (*s && *s != c)
				s++;
	}
	if (new_str)
		new_str[i] = NULL;
	return (new_str);
}
