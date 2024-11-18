/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:46:49 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/03/29 09:18:52 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		counter;
	int		x;

	counter = 0;
	x = 0;
	va_start(args, text);
	while (text[x] != '\0')
	{
		if (text[x] == '%')
		{
			ft_format(text, args, &counter, x);
			x++;
		}
		else
			ft_char(text[x], &counter);
		if (counter == (int) - 1)
			return (counter);
		x++;
	}
	va_end(args);
	return (counter);
}
