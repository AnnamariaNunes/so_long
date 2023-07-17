/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:57:05 by aangelic          #+#    #+#             */
/*   Updated: 2023/07/06 14:01:25 by aangelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horizontalwall(t_game *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (game->map[0][j] != '1' || game->map[game->heightmap - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	verticalwall(t_game *game)
{
	int	height;

	height = 0;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][ft_strlen(game->map[height]) - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

void	if_walls(t_game *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\nThis map is missing the walls\n");
		exit_point(game);
	}
}

void	count_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C')
	{
		printf("\nError Here!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->collectcount++;
	if (game->map[height][width] == 'P')
	{
		game->playercount++;
		game->x_axis = width;
		game->y_axis = height;
	}
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width < game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->collectcount > 1
			&& game->exitcount == 1))
	{
		printf("Error\nSomething is wrong!\n");
		exit_point(game);
	}
}
