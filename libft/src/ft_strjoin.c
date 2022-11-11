/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:52:42 by dgross            #+#    #+#             */
/*   Updated: 2022/05/01 19:24:30 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // malloc

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (s1[0] == '\0' && s2[0] == '\0')
	len++;
	new_string = malloc (sizeof(char) * (len));
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s1, len);
	ft_strlcat(new_string, s2, len);
	return (new_string);
}
