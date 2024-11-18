/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:41:59 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/04/06 17:58:05 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char *text, va_list args, int *counter, int i)
{
	if (text[i + 1] == 'c')
		ft_char(va_arg(args, int), counter);
	else if (text[i + 1] == 's')
		ft_string(va_arg(args, char *), counter);
	else if (text[i + 1] == 'u')
		ft_base10(va_arg(args, int), counter);
	else if (text[i + 1] == 'd' || text[i + 1] == 'i')
		ft_number((long long)va_arg(args, int), counter);
	else if (text[i + 1] == 'x')
		ft_hex(va_arg(args, int), "0123456789abcdef", counter);
	else if (text[i + 1] == 'X')
		ft_hex(va_arg(args, int), "0123456789ABCDEF", counter);
	else if (text[i + 1] == 'p')
	{
		ft_string("0x", counter);
		if (*counter == (int) - 1)
			return ;
		ft_hexp(va_arg(args, long), "0123456789abcdef", counter);
	}
	else if (text[i + 1] == '%')
		ft_char((int) '%', counter);
}
