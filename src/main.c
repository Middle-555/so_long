#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	game;

	if (argc != 2)
	{
		ft_printf("Usage: %s [map.ber]\n", argv[0]);
		return (1);
	}
	// Initialisation de la carte
	game.map.path = argv[1];
	if (!map_parser(&(game.map)))
		return (1);
	// Initialisation du jeu
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_printf("Error: Failed to initialize mlx.\n");
		return (1);
	}
	game.sprite = init_sprites(game.mlx);
	if (!game.sprite.player || !game.sprite.exit || !game.sprite.collectible
		|| !game.sprite.wall || !game.sprite.ground)
	{
		ft_printf("Error: Failed to load sprites.\n");
		return (1);
	}
	// create_game_window(&game, game.map.height, game.map.width);
	// Affichage de la carte initiale
	put_sprite_on_screen(&game, 50, 50);
	// Boucle principale du jeu
	mlx_loop(game.mlx);
	// Libération de la mémoire
	free_game(&game);
	return (0);
}
