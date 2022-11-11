/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:02:54 by dgross            #+#    #+#             */
/*   Updated: 2022/09/09 13:44:11 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_putnbr_fd ft_putstr_fd

#include <stddef.h> // NULL
#include <stdlib.h> // malloc free

// counts the length for the hexadecimal number by dividing by 16.
// returning the lenght + 1 for the \0.
static int	ft_digitlen(unsigned long int digit)
{
	int	i;

	i = 0;
	while (digit != 0)
	{
		digit = digit / 16;
		i++;
	}
	return (i + 1);
}

// divide digit by 16 and return the remaining value to remainder (modulo).
// If the remainder is less than 10, it should be added with char '0',
// otherwise with 'W' or if typ = X, it should be added with char '7'.
// Each char is then given into the string from the back to the front.
static char	*get_digit(unsigned long int digit, char *s, int i, const char *str)
{
	long	remainder;

	remainder = 0;
	while (digit != 0)
	{
		remainder = digit % 16;
		if (remainder < 10)
			s[--i] = '0' + remainder;
		else
		{
			if (*str == 'X')
				s[--i] = '7' + remainder;
			else
				s[--i] = 'W' + remainder;
		}
		digit = digit / 16;
	}
	return (s);
}

void	*ft_printstr(unsigned long int digit, int i, const char *str)
{
	char	*string;

	string = malloc(sizeof(char) * i);
	if (string == NULL)
		return (NULL);
	i--;
	string[i] = '\0';
	get_digit(digit, string, i, str);
	ft_putstr_fd(string, 1);
	free (string);
	return (NULL);
}

// checks if digit = 0 and returned a "0" string and prints a 0.
// Counts the digit length, creates a string for the lenght and
// puts a \0 at the end of the string.
// After the calculation in get_digit the string is printed.
int	ft_puthexnbr(unsigned long int digit, const char *str)
{
	int		i;

	if (digit == 0)
	{
		ft_putnbr_fd(0, 1);
		return (2);
	}
	i = ft_digitlen(digit);
	ft_printstr(digit, i, str);
	return (i);
}
