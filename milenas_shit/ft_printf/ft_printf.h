/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:34:24 by milferna          #+#    #+#             */
/*   Updated: 2025/07/29 01:36:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_strlen(const char *a);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_base(unsigned long n, char *base);
int	ft_put_ptr(void *ptr, char *base);
int	ft_check(va_list *args, char a);
int	ft_printf(const char *a, ...);
int	ft_putstr(const char *a);

#endif
