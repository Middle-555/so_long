#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	// Vérification du nombre d'arguments
	if (argc != 2)
	{
		ft_printf("Usage: %s [map_file]\n", argv[0]);
		return (1);
	}
	// Initialisation de la structure t_map
	map.path = argv[1];
	map.height = 0;
	map.width = 0;
	// Vérification et parsing de la carte
	if (map_parser(&map))
		return (1);
	// Allocation de la mémoire pour le tableau de la carte
	if (tab_filler(&map, &map.map))
	{
		ft_printf("Error: Memory allocation failed.\n");
		return (1);
	}
	// Vérification des murs de la carte
	if (check_wall_error(&map))
	{
		ft_printf("Error: Wall check failed.\n");
		return (1);
	}
	ft_printf("Map dimensions: %d x %d\n", map.height, map.width);
	ft_printf("Map data:\n");
	for (int i = 0; i < map.height; i++)
	{
		ft_printf("%s\n", map.tab[i]);
	}
	// Libération de la mémoire allouée pour la carte
	for (int i = 0; i < map.height; i++)
	{
		free(map.tab[i]);
	}
	free(map.tab);
	return (0);
}
