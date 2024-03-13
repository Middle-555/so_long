/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:48:17 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/13 11:25:01 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	map.path = argv[1];
	if (argc != 2)
	{
		ft_printf("Usage: ./so_short <map_file.ber>\n");
		return (1);
	}
	map_stock(&map);
	not_enough_exit(&map);
	check_player(&map);
	not_enough_collectible(&map);
	not_rectangular(&map);
}

/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (1);
	}

	const char *map_file = argv[1];
	int fd = open(map_file, O_RDONLY);
	if (fd == -1) {
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}

	char buffer[1024];
	ssize_t bytes_read;
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
		// Traitement du contenu du fichier ici
		fwrite(buffer, sizeof(char), bytes_read, stdout);
	}

	if (bytes_read == -1) {
		perror("Erreur lors de la lecture du fichier");
		close(fd);
		return (1);
	}

	close(fd);
	return (0);
}*/
