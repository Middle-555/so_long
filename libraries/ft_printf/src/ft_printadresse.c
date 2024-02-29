/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadresse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:41:54 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/19 16:10:00 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printadresse(void *adresse)
{
	int		count;

	count = 0;
	if (adresse == NULL)
	{
		count += ft_putstr("0x0");
		return (count);
	}
	else
	{
		count += ft_putstr("0x");
		count += ft_printhexa_low((unsigned long)adresse);
		return (count);
	}
}
