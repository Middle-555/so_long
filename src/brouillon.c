/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brouillon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:28:43 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/19 20:31:09 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
void	game_success(t_so_long *game)
{
	ft_printf("%s \n", "Congratulation you finished the game.");
	free_game(game);
}


// Check if there is 1 exit.
int	not_enough_exit(t_so_long *game)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[i][j] == EXIT)
			{
				exit++;
				//game->end.x = j;
				//game->end.y = i;
				//ft_printf("%d y test\n", i);
				//ft_printf("%d x  test\n", j);
				//ft_printf("%d x \n", game->end.x);
				//ft_printf("%d y \n", game->end.y);
			}
			j++;
		}
		i++;
	}
	if (exit != 1)
		map_error("Please put 1 exit.");
	return (0);
}

*/