/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:56:54 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/02/29 16:12:33 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_number(long long num, int *counter)
{
	char	num_str[22];
	int		len;
	int		i;

	len = 0;
	ft_putnbr_pf(num, num_str);
	while (num_str[len] != '\0')
	{
		len++;
	}
	i = write(1, num_str, len);
	if (i == -1)
	{
		*counter = -1;
	}
	else
	{
		*counter += i;
	}
	return (len);
}
