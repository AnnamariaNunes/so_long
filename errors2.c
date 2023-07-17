/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:56:45 by aangelic          #+#    #+#             */
/*   Updated: 2023/07/06 13:39:38 by aangelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(t_game *game)
{
	if_walls(game);
	character_valid(game);
}

void	map_error(t_game *game)
{
	write(2, "Error: Map not supported\n", 25);
	free_matrix(game->map);
	exit(EXIT_FAILURE);
}

int	check_map_size(t_game *game)
{
	int	i;
	int	j;
	int	line_size;

	i = 0;
	while (game->map[++i])
	{
		j = 0;
		line_size = 0;
		while (game->map[i][j])
			if (game->map[i][j++] != '\n')
				line_size++;
		if (line_size != game->widthmap)
			return (0);
	}
	return (1);
}

int	check_limits(t_game *game)
{
	int	i;
	int	j;

	j = game->heightmap - 1;
	i = 0;
	while (i < game->widthmap)
	{
		if (game->map[0][i] == '1' && game->map[j][i] == '1')
			i++;
		else
			return (0);
	}
	j = game->widthmap - 1;
	i = 0;
	while (i < game->heightmap)
	{
		if (game->map[i][0] == '1' && game->map[i][j] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

void	check_errors2(t_game *game)
{
	if (!game->map)
		map_error(game);
	else if (!check_map_size(game) || (game->heightmap == game->widthmap))
		map_error(game);
	else if (game->exitcount != 1)
		map_error(game);
	else if (!check_limits(game))
		map_error(game);
	else if (game->playercount != 1)
		map_error(game);
	if (!handle_flood_fill(game))
		map_error(game);
}
