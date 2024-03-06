#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	game;

	// Vérification du nombre d'arguments
	if (argc != 2)
	{
		ft_printf("Usage: %s [map_file]\n", argv[0]);
		return (1);
	}
	// Initialisation de la structure t_so_long
	ft_bzero(&game, sizeof(t_so_long));
	game.map.path = argv[1];
	// Vérification et parsing de la carte
	if (map_parser(&game.map))
		return (1);
	// Allocation de la mémoire pour le tableau de la carte
	alloc_map(&game);
	// Remplissage de la carte à partir du fichier
	fill_map(&game, game.map.path);
	// Vérification des murs de la carte
	if (check_wall_error(&game.map))
	{
		ft_printf("Error: Wall check failed.\n");
		return (1);
	}
	ft_printf("Map dimensions: %d x %d\n", game.map.height, game.map.width);
	ft_printf("Map data:\n");
	for (int i = 0; i < game.map.height; i++)
	{
		ft_printf("%s\n", game.map.tab[i]);
	}
	// Libération de la mémoire allouée pour la carte
	for (int i = 0; i < game.map.height; i++)
	{
		free(game.map.tab[i]);
	}
	free(game.map.tab);
	return (0);
}
