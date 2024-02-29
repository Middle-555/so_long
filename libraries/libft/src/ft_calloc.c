/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:59:47 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/19 16:42:21 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	*ft_memsetalt(size_t size)
{
	size_t	i;
	void	*new;

	new = (void *) malloc (size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(unsigned char *)(new + i) = 0;
		i++;
	}
	return (new);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	if (size != 0 && nmemb > ((size_t) - 1 / size))
		return (0);
	return (ft_memsetalt(nmemb * size));
}
