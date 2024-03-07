#include "../include/so_long.h"
/*
// Définition de la fonction de test
void test_functions(t_so_long *game)
{
    ft_printf("\nTesting map_parser...\n");
    map_parser(&(game->map));
    ft_printf("\nTesting alloc_map...\n");
    alloc_map(game);
    ft_printf("\nTesting fill_map...\n");
    fill_map(game, game->map.path); // Ajoute le chemin du fichier
    ft_printf("\nTesting check_wall_error...\n");
    check_wall_error(&(game->map));
    // Ajoute d'autres tests pour les autres fonctions ici
}

int main(int argc, char **argv)
{
    t_so_long game;

    // Vérification du nombre d'arguments
    if (argc != 2)
    {
        ft_printf("Usage: %s [map_file]\n", argv[0]);
        return (1);
    }

    // Initialisation de la structure t_so_long
    game.map.path = argv[1];
    game.map.height = 0;
    game.map.width = 0;

    // Vérification et parsing de la carte
    if (map_parser(&(game.map)))
        return (1);

    // Allocation de la mémoire pour le tableau de la carte
    alloc_map(&game);

    // Remplissage de la carte à partir du fichier
    fill_map(&game, game.map.path);

    // Vérification des murs de la carte
    if (check_wall_error(&(game.map)))
    {
        ft_printf("Error: Wall check failed.\n");
        return (1);
    }

    // Initialisation de la fenêtre de jeu
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_printf("Error: Failed to initialize mlx.\n");
        return (1);
    }
    create_game_window(&game, game.map.width, game.map.height);

    // Initialisation des sprites
    game.sprite = init_sprites(game.mlx);

    ft_printf("Map dimensions: %d x %d\n", game.map.height, game.map.width);
    ft_printf("Map data:\n");
    for (int i = 0; i < game.map.height; i++)
    {
        ft_printf("%s\n", game.map.tab[i]);
    }

    // Appel de la fonction de test
    test_functions(&game);

    // Libération de la mémoire allouée pour la carte
    for (int i = 0; i < game.map.height; i++)
    {
        free(game.map.tab[i]);
    }
    free(game.map.tab);

    // Boucle principale de la fenêtre
    mlx_loop(game.mlx);

    return (0);
}

*/



void test_alloc_map()
{
    t_so_long game;

    alloc_map(&game);
    // Insérez ici les assertions pour vérifier si l'allocation a réussi
}

void test_fill_map()
{
    t_so_long game;
    const char *path = "map/map_valid.ber";

    alloc_map(&game);
    fill_map(&game, path);
    // Insérez ici les assertions pour vérifier si le remplissage de la carte a réussi
}


void test_read_map()
{
    t_so_long game;
    const char *file = "map/map_valid.ber";

    // Initialisez les autres éléments de la structure game nécessaires pour le test
    read_map(&game, file);
    // Insérez ici les assertions pour vérifier si la lecture de la carte a réussi
}



int main()
{
    // Test de la fonction alloc_map
    test_alloc_map();

    // Test de la fonction fill_map
    test_fill_map();

    // Test de la fonction read_map
    test_read_map();

    return 0;
}

