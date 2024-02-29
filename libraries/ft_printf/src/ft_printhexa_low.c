/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:17:10 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/19 16:10:19 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printhexa_low(unsigned long nb)
{
	char	*tab;
	int		count;

	count = 0;
	tab = "0123456789abcdef";
	if (nb < 16)
		count += ft_putchar(tab[nb]);
	else
	{
		count += ft_printhexa_low (nb / 16);
		count += ft_putchar(tab [nb % 16]);
	}
	return (count);
}
