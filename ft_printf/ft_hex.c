/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:06:30 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/02/29 10:36:09 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int num, char *hex_digits, int *counter)
{
	unsigned int	base;
	size_t			len;
	int				ret;

	base = ft_strlen(hex_digits);
	if (base == 0)
		return (-1);
	if (num >= base)
	{
		ret = ft_hex(num / base, hex_digits, counter);
		if (ret == -1)
			return (-1);
		num %= base;
	}
	len = write(1, &hex_digits[num], 1);
	if (len == (size_t)-1)
		*counter = -1;
	else
		*counter += 1;
	return (*counter);
}
