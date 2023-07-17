/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainControls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:03:48 by aangelic          #+#    #+#             */
/*   Updated: 2023/07/14 14:52:45 by aangelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_convert(char *s, int len, long int n)
{
	while (n > 0)
	{
		s[len] = 48 + (n % 10);
		n /= 10;
		len--;
	}
	return (s);
}

static int	ft_intlen(long int li)
{
	int	i;

	i = 0;
	if (li == 0)
		return (1);
	if (li < 0)
	{
		i++;
		li *= -1;
	}
	while (li > 0)
	{
		i++;
		li = li / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	li;
	char		*s;
	int			len;

	li = n;
	len = ft_intlen(li);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = 48;
	if (li < 0)
	{
		s[0] = '-';
		li *= -1;
	}
	return (s = ft_convert(s, len, li));
}

int	controls_working(int command, t_game *game)
{
	int		works;
	char	*moves;

		
	if (command == 65307)
		exit_point(game);
	if (command == 119)
		works = keyboard_w(game, command);
	if (command == 115)
		works = keyboard_s(game, command);
	if (command == 97)
		works = keyboard_a(game, command);
	if (command == 100)
		works = keyboard_d(game, command);
	if (works)
	{
		adding_in_graphics_cpe(game);
		adding_in_graphics_10(game);
		moves = ft_itoa(game->counter);
		mlx_string_put(game->mlxpointer, game->winpointer, 
			50, 50, 0xFFFFFFFF, moves);
		free(moves);
	}
	return (1);
}
