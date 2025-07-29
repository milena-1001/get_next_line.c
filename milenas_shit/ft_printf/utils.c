/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:14:02 by milferna          #+#    #+#             */
/*   Updated: 2025/07/29 01:39:15 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *a)
{
	size_t	i;

	if (!a)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			count = 11;
			return (count);
		}
		else
		{
			ft_putchar('-');
			n *= -1;
			count = 1;
		}
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	count;
	int	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (n >= (unsigned long)base_len)
		count += ft_putnbr_base(n / base_len, base);
	count += ft_putchar(base[n % base_len]);
	return (count);
}

int	ft_put_ptr(void *ptr, char *base)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	ft_putstr("0x");
	return (2 + ft_putnbr_base(n, base));
}
