#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Usage: %s [map.ber]\n", argv[0]);
		return (1);
	}
	// Initialiser la structure de la carte avec le chemin du fichier de la carte
	map.path = argv[1];
	// Appeler map_parser pour lire et traiter la carte
	if (map_parser(&map) != 0)
	{
		ft_printf("Error parsing map.\n");
		return (1);
	}
	// Afficher les dimensions de la carte pour vérification
	ft_printf("Map height: %d, width: %d\n", map.height, map.width);
	// Libérer la mémoire utilisée par la structure de la carte
	// Ne pas oublier de libérer map.tab si vous l'allouez dans map_parser
	return (0);
}
