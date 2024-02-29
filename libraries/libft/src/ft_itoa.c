/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:23:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/19 16:42:21 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	sign(long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		n = n * (-1);
		size = 1;
	}
	if (n == 0)
		size = 1;
	else
	{
		while (n)
		{
			n = n / 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*s1;
	long	nb;
	int		is_negative;

	size = sign((long)n);
	s1 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s1)
		return (NULL);
	nb = ((long) n);
	is_negative = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		s1[0] = '-';
		is_negative = 1;
	}
	s1[size] = '\0';
	while (size > (size_t) is_negative)
	{
		s1[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (s1);
}
