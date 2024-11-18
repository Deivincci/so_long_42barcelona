/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:45:13 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/03/29 09:17:42 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	total_len;
	int		i;
	int		j;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc((total_len + 1) * sizeof(char));
	if (!joined)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free (s1);
	ft_bzero(s2, ft_strlen(s2));
	return (joined);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	x;
	char	*ptr_s;
	char	ptr_c;

	x = 0;
	ptr_s = (char *)s;
	ptr_c = (char)c;
	if (!s)
		return (NULL);
	while (s[x] != '\0' && s[x] != ptr_c)
		x++;
	if (s[x] == ptr_c)
		return (&ptr_s[x]);
	return (NULL);
}

void	ft_bzero(char *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)s++ = 0;
}
