/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:57:43 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/02/23 08:29:12 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* ft_numlen is a helper function to calculate the length of a given integer
 in digits.
ft_convert_to_string is a helper function used to convert an integer to a
 string of characters.
ft_itoa is a function in C that converts an integer to a string of characters*/
static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
	{
		len = 1;
	}
	else if (n < 0)
	{
		while (n != 0)
		{
			n /= 10;
			len++;
		}
		len++;
	}
	else
	{
		while (n != 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

static void	ft_convert_to_string(int n, char *result, size_t len)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		result[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_memset(result, '\0', (len + 1) * sizeof(char));
	ft_convert_to_string(n, result, len);
	return (result);
}
