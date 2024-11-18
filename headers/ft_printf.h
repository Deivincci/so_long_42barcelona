/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:18:56 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/03/29 09:11:42 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(const char *text, ...);
void	ft_format(const char *text, va_list args, int *counter, int i);

size_t	ft_strlen(const char *s);
char	ft_char(char c, int *counter);
int		ft_string(const char *str, int *counter);
int		ft_hex(unsigned int num, char *hex_digits, int *counter);
void	ft_hexp(unsigned long num, char *hex_digits, int *counter);
void	ft_base10(unsigned int num, int *counter);
int		ft_number(long long num, int *counter);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void	ft_putnbr_pf(long long n, char *num_str);

#endif
