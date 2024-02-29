/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:25:10 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/19 16:43:46 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_format(char format_type, va_list args)
{
	int		count;

	count = 0;
	if (format_type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format_type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format_type == 'p')
		count += ft_printadresse(va_arg(args, void *));
	else if (format_type == 'x')
		count += ft_printhexa_low((long)va_arg(args, unsigned int));
	else if (format_type == 'X')
		count += ft_printhexa_upper((long)va_arg(args, unsigned int));
	else if (format_type == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (format_type == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format_type == '%')
		count += ft_putchar('%');
	else if (format_type == 'u')
		count += ft_printunsigned_decimal(va_arg(args, unsigned int));
	return (count);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, type);
	while (*type != '\0')
	{
		if (*type == '%')
			count += ft_format(*++type, args);
		else
			count += ft_putchar(*type);
		++type;
	}
	va_end(args);
	return (count);
}
