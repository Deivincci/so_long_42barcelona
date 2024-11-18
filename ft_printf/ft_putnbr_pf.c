/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:23:06 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/02/29 16:11:41 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*used to print an integer "n" to the specified file descriptor "fd"*/
static void	ft_putnbr_aux(unsigned int n, char *num_str, int *len)
{
	if (n < 10)
		num_str[(*len)++] = n + '0';
	else
	{
		ft_putnbr_aux(n / 10, num_str, len);
		num_str[(*len)++] = n % 10 + '0';
	}
}

void	ft_putnbr_pf(long long n, char *num_str)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		num_str[len++] = '-';
		n = -n;
	}
	ft_putnbr_aux(n, num_str, &len);
	num_str[len] = '\0';
}
