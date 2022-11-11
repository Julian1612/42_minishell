/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:02:25 by dgross            #+#    #+#             */
/*   Updated: 2022/09/09 13:44:01 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 
// ft_puthexnbr ft_countnbr ft_putunsigned ft_putptr ft_putstring 
#include "libft.h" // ft_strlen ft_putnbr_fd ft_putchar_fd ft_strdup 

#include <stdio.h> // free NULL
#include <stdarg.h> // for va_*
#include <stdlib.h> // free NULL

// checks if char after % is x, X , u or a % sign
static int	ft_find_num(int i, va_list arg, const char *s, int len)
{
	int		intsave;

	if (s[i] == 'x' || s[i] == 'X')
		len += ft_puthexnbr(va_arg(arg, unsigned int), &s[i]) - 1;
	else if (s[i] == 'd' || s[i] == 'i')
	{
		intsave = va_arg(arg, int);
		ft_putnbr_fd(intsave, 1);
		len += ft_countnbr(intsave);
	}
	else if (s[i] == 'u')
		len += ft_putunsigned(va_arg(arg, unsigned int));
	else if (s[i] == '%')
	{
		ft_putchar_fd('%', 1);
		len += 1;
	}
	return (len);
}

// checks if the char after % is a c, p or s otherwise it prints the char
static int	ft_find(int i, va_list arg, const char *string, int len)
{	
	char	*save;

	if (string[i] == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		len += 1;
	}
	else if (string[i] == 'p')
		len += ft_putptr(va_arg(arg, unsigned long int), &string[i]) + 1;
	else if (string[i] == 's')
	{
		save = va_arg(arg, char *);
		ft_putstring(save);
		if (save == NULL)
			len += 6;
		else
			len += ft_strlen(save);
	}
	else
		ft_putchar_fd(string[i], 1);
	return (len);
}

// goes through the string and looks for a % character and
// prints every char that isn't a % sign.
// If a % character is found, the type is searched and 
// passed to the other function.
static int	ft_get_typ(const char *s, int len, int i, va_list arg)
{
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'd' || s[i] == 'u' || s[i] == 'i'
				|| s[i] == 'x' || s[i] == 'X' || s[i] == '%')
				len = ft_find_num(i, arg, s, len) - 1;
			else
				len = ft_find(i, arg, s, len) - 1;
			len -= 1;
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i + len);
}

// creats a argment list and passes everything to ft_get_typ.
int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (arg, s);
	len = ft_get_typ(s, len, i, arg);
	va_end (arg);
	return (len);
}
