/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:17:01 by milferna          #+#    #+#             */
/*   Updated: 2025/07/29 01:38:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *a)
{
	size_t	i;

	if (!a)
		return (ft_putstr("(null)"));
	i = 0;
	while (a[i] != '\0')
	{
		write(1, &a[i], 1);
		i++;
	}
	return (i);
}

int	ft_check(va_list *args, char a)
{
	int	i;

	i = 0;
	if (a == 'c')
		i = ft_putchar(va_arg(*args, int));
	else if (a == 'i' || a == 'd')
		i = ft_putnbr(va_arg(*args, int));
	else if (a == 's')
		i = ft_putstr(va_arg(*args, char *));
	else if (a == 'x')
		i = ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (a == 'X')
		i = ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (a == 'p')
		i = ft_put_ptr(va_arg(*args, void *), "0123456789abcdef");
	else if (a == '%')
		i = ft_putchar('%');
	else if (a == 'u')
		i = ft_putnbr_base(va_arg(*args, unsigned int), "0123456789");
	return (i);
}

int	ft_printf(char const *a, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	va_start(args, a);
	while (a[i] != '\0')
	{
		if (a[i] == '%' && a[i + 1] != '\0')
		{
			i ++;
			count += ft_check(&args, a[i]);
		}
		else
		{
			count += ft_putchar(a[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int				f;
// 	int				p;

// 	f = ft_printf("Hola %c%c%%\n", '0', 'k');
// 	p = printf("Hola %c%c\n", '0', 'k');
// 	printf("ft_printf devolvió: %d\n", f);
// 	printf("printf devolvió: %d\n", p);
// 	return (0);
// }
