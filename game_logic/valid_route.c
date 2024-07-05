/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changeit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:16:01 by irlozano          #+#    #+#             */
/*   Updated: 2024/06/27 13:16:03 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	flood_fill(t_complete *game, char **map, int x_pos, int y_pos)
{
	if (y_pos < 0 || y_pos >= game->heightmap || x_pos < 0
		|| x_pos >= game->widthmap
		|| map[y_pos][x_pos] == 'P'
		|| map[y_pos][x_pos] == '1')
		return ;
	if (map[y_pos][x_pos] == 'C')
		game->coinparse++;
	if (map[y_pos][x_pos] == 'E')
	{
		map[y_pos][x_pos] = 'P';
		game->exitparse++;
		return ;
	}
	map[y_pos][x_pos] = 'P';
	flood_fill(game, map, (x_pos - 1), y_pos);
	flood_fill(game, map, (x_pos + 1), y_pos);
	flood_fill(game, map, x_pos, (y_pos - 1));
	flood_fill(game, map, x_pos, (y_pos + 1));
}

char	**make_area(t_complete *game, char	**zone)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * game->heightmap);
	while (i < game->heightmap)
	{
		new[i] = malloc(sizeof(char) * (game->widthmap + 1));
		while (j < game->widthmap)
		{
			new[i][j] = zone[i][j];
			j++;
		}
		new[i][game->widthmap] = '\0';
		j = 0;
		i++;
	}
	return (new);
}

void	valid_route(t_complete *game)
{
	char	**area;
	int		line;

	line = 0;
	area = make_area(game, game->map);
	area[game->y_axis][game->x_axis] = 'B';
	flood_fill(game, area, game->x_axis, game->y_axis);
	while (line < game->heightmap)
	{
		if (area[line])
			free(area[line++]);
	}
	if (area)
		free(area);
	if (game->coincount != game->coinparse
		|| game->exitcount != game->exitparse)
	{
		ft_printf(RED"\nError\nOh, oh! 🙈\nThe exit "RESET);
		ft_printf(RED"or some collectables are not accessible!\n"RESET);
		exit_point(game);
	}
}
