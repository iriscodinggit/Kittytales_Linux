/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorschars_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:07:42 by irlozano          #+#    #+#             */
/*   Updated: 2024/06/26 14:07:50 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "get_next_linei.h"
#include "ft_printf.h"

void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf(RED "\nError\nOh, oh! 🙈\nThere's an invalid char", RESET);
		ft_printf(RED " in the map: %c\n", game->map[height][width], RESET);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->coincount++;
	if (game->map[height][width] == 'P')
	{
		game->y_axis = height;
		game->x_axis = width;
		game->playercount++;
	}
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->coincount >= 1
			&& game->exitcount == 1))
	{
		ft_printf(RED "\nError\nOh, oh! 🙈\nMap error" RESET);
		ft_printf(RED " or number of P, E or C is wrong!\n" RESET);
		exit_point(game);
	}
}
