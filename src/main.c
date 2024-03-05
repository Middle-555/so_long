/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:09:24 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/01 12:59:56 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		map_error("Plese add the map.");
	else if (argc > 2)
		map_error("There is too many argument. Run the program with the map.");
	else if (argc == 2 && check_ber_format(argv[1]) == 1)
	{
	}
}
