/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 08:51:42 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/03/01 10:27:38 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*It is used to initialize a block of memory with a given value of int c,
especially useful for organizing memory in programs. */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pb;
	size_t			i;

	pb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		pb[i] = c;
		i++;
	}
	return (b);
}
