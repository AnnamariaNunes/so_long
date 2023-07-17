/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:01:28 by aangelic          #+#    #+#             */
/*   Updated: 2023/07/06 13:53:32 by aangelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y, int *counter)
{
	char	**map;

	map = game->map;
	if (x < 0 || y < 0 || x >= game->widthmap || y >= game->heightmap || \
		map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		*counter += 1;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'F';
	flood_fill(game, x + 1, y, counter);
	flood_fill(game, x - 1, y, counter);
	flood_fill(game, x, y + 1, counter);
	flood_fill(game, x, y - 1, counter);
}

int	handle_flood_fill(t_game *game)
{
	int		counter;
	char	**map_tmp;
	char	**orig_map;
	int		i;

	map_tmp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!map_tmp)
		return (0);
	counter = 0;
	i = -1;
	while (game->map[++i])
		map_tmp[i] = ft_strdup(game->map[i]);
	map_tmp[i] = NULL;
	orig_map = game->map;
	game->map = map_tmp;
	flood_fill(game, game->x_axis, game->y_axis, &counter);
	free_matrix(map_tmp);
	game->map = orig_map;
	return (counter == (game->exitcount + game->collectcount));
}
