/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:42:54 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/02/29 15:05:08 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_char(char c, int *counter)
{
	int	len;

	len = write(1, &c, 1);
	if (len == -1)
	{
		if (counter != NULL)
		{
			*counter = -1;
		}
		return (-1);
	}
	else
		(*counter)++;
	return (c);
}
