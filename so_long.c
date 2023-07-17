/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:56:59 by aangelic          #+#    #+#             */
/*   Updated: 2023/07/14 13:43:12 by aangelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

static void	free_mlx_images(t_game *game)
{
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	if (game->floor)
		mlx_destroy_image(game->mlxpointer, game->floor);
	if (game->barrier)
		mlx_destroy_image(game->mlxpointer, game->barrier);
	if (game->player)
		mlx_destroy_image(game->mlxpointer, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlxpointer, game->exit);
	if (game->collectable)
		mlx_destroy_image(game->mlxpointer, game->collectable);
}

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	free_mlx_images(game);
	if (game->mlxpointer)
	{
		mlx_destroy_display(game->mlxpointer);
		free(game->mlxpointer);
	}
	if (line < game->heightmap)
	{
		while (line < game->heightmap)
			free(game->map[line++]);
		free(game->map);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write (2, "Coloca o map carai!!!! OU argc correta! \n", 42);
		return (0);
	}
	game.game_start = 0;
	ft_memset(&game, 0, sizeof(t_game));
	map_reading(&game, argv);
	check_errors(&game);
	check_errors2(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 40),
			(game.heightmap * 40), "aangelic's game");
	place_images_in_game(&game);
	adding_in_graphics_10(&game);
	adding_in_graphics_cpe(&game);
	game.game_start = 1;
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit_point, &game);
	mlx_loop(game.mlxpointer);
}
