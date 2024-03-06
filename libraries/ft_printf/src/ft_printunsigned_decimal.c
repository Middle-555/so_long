/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:08:08 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/06 10:32:24 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printunsigned_decimal(unsigned int nb)
{
	int		count;

	count = 0;
	if (nb >= '0' && nb <= '9')
	{
		count += ft_putchar(nb + '0');
	}
	else
	{
		count += ft_printunsigned_decimal (nb / 10);
		count += ft_printunsigned_decimal (nb % 10);
	}
	return (count);
}
