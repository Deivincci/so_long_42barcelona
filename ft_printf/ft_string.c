/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:11:14 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/02/29 15:08:13 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	protect_str(const char *str, int *counter)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	len = write(1, str, len);
	if (len == -1)
	{
		if (counter != NULL)
			*counter = -1;
		return (-1);
	}
	if (counter != NULL)
		*counter += len;
	return (len);
}

int	ft_string(const char *str, int *counter)
{
	if (str == NULL)
	{
		return (protect_str("(null)", counter));
	}
	else
	{
		return (protect_str(str, counter));
	}
}
