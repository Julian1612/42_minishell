/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:42:58 by dgross            #+#    #+#             */
/*   Updated: 2022/05/20 12:53:44 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
int		ft_puthexnbr(unsigned long int digit, const char *string);
int		ft_putunsigned(int digit);
int		ft_putptr(unsigned long int ptr, const char *str);
int		ft_countnbr(int digit);
void	ft_putstring(char *s);

#endif