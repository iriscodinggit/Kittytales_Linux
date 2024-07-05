/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:20:45 by irlozano          #+#    #+#             */
/*   Updated: 2024/06/26 14:20:47 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 160, height * 160);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 160, height * 160);
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/bigflowr.xpm", &i, &j);
	if (!game->floor)
		exit_point(game);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/bigwall.xpm", &i, &j);
	if (!game->barrier)
		exit_point(game);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/bigcatgood.xpm", &i, &j);
	if (!game->player)
		exit_point(game);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/bigdoor.xpm", &i, &j);
	if (!game->exit)
		exit_point(game);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/bigcoin.xpm", &i, &j);
	if (!game->collectable)
		exit_point(game);
}

void	place_1e0(t_complete *game, int height, int width, char c)
{
	if (c == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, width * 160, height * 160);
	if (c == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, width * 160, height * 160);
	if (c == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->barrier, width * 160, height * 160);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			else
				place_1e0(game, height, width, game->map[height][width]);
			width++;
		}
		height++;
	}
}
