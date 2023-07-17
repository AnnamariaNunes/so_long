/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:49:52 by aangelic          #+#    #+#             */
/*   Updated: 2023/07/06 13:04:59 by aangelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "minilibx-linux-master/mlx.h"

typedef struct t_start
{
	int		fd;
	int		game_start;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		collectcount;
	int		exitcount;
	int		moves_count;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;
	char	**map;
	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;
	void	*initmlx;

}	t_game;

int		exit_point(t_game *game);
int		map_reading(t_game *game, char **argv);
int		controls_working(int command, t_game *game);
void	adding_in_graphics_10(t_game *game);
void	adding_in_graphics_cpe(t_game *game);
void	place_images_in_game(t_game *game);
void	check_errors(t_game *game);
void	character_valid(t_game *game);
int		horizontalwall(t_game *game);
int		verticalwall(t_game *game);
void	if_walls(t_game *game);
void	count_checker(t_game *game, int height, int width);
int		keyboard_w(t_game *game, int movement);
int		right_move(t_game *game, int i, int j);
int		keyboard_s(t_game *game, int movement);
int		keyboard_a(t_game *game, int movement);
int		keyboard_d(t_game *game, int movement);
char	*ft_itoa(int n);
int		handle_flood_fill(t_game *game);
void	flood_fill(t_game *game, int x, int y, int *counter);
void	free_matrix(char **matrix);
void	check_errors2(t_game *game);

#endif
