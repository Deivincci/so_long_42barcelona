/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:06:29 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/02/29 10:40:29 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexp(unsigned long num, char *hex_digits, int *counter)
{
	unsigned long	base;
	size_t			len;

	base = ft_strlen(hex_digits);
	if (num >= base)
	{
		ft_hexp(num / base, hex_digits, counter);
		num %= base;
	}
	len = write(1, &hex_digits[num], 1);
	if (len == (size_t) - 1)
		*counter = -1;
	else
		*counter += 1 ;
}
