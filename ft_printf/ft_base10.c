/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:23:16 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/02/29 16:08:16 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	auxbase(unsigned int num, unsigned int base, int *counter)
{
	char	digit;
	int		len;

	if (num >= base)
	{
		auxbase(num / base, base, counter);
		if (*counter == -1)
			return ;
		num %= base;
	}
	digit = '0' + num;
	len = write(1, &digit, 1);
	if (len == -1)
	{
		*counter = -1;
	}
	else
		(*counter)++;
}

void	ft_base10(unsigned int num, int *counter)
{
	unsigned int	base;
	char			digit;

	base = 10;
	if (num == 0)
	{
		digit = '0';
		if (write(1, &digit, 1) == -1)
		{
			*counter = -1;
			return ;
		}
		else
			(*counter)++;
	}
	else
	{
		auxbase(num, base, counter);
		if (*counter == -1)
			return ;
	}
}
