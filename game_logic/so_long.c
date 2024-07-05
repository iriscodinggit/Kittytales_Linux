/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:35:00 by irlozano          #+#    #+#             */
/*   Updated: 2024/07/01 16:01:04 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

void	free_array(t_complete *game, char **array)
{
	int	i;

	i = 0;
	while (i < game->heightmap)
	{
		if (array[i] != NULL)
			free(array[i++]);
	}
	if (array)
		free(array);
}

int	exit_point(t_complete *game)
{
	if (game->map)
		free_array(game, game->map);
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
	if (game->winpointer)
	{
		mlx_destroy_window(game->mlxpointer, game->winpointer);
		game->winpointer = NULL;
	}
	if (game->mlxpointer)
	{
		mlx_loop_end(game->mlxpointer);
		mlx_destroy_display(game->mlxpointer);
		free(game->mlxpointer);
		game->mlxpointer = NULL;
	}
	exit(0);
}

void	init(t_complete *game)
{
	game->mlxpointer = mlx_init();
	if (!game->mlxpointer)
	{
		ft_printf(RED "\nError\nThere's no mlxpointer!🙈" RESET);
		exit_point(game);
	}
	game->winpointer = mlx_new_window(game->mlxpointer, (game->widthmap * 160),
			(game->heightmap * 160), "KittyTales by Iris <3");
	if (!game->winpointer)
	{
		ft_printf(RED "\nError\nThere's no winpointer!🙈" RESET);
		exit_point(game);
	}
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
	{
		ft_printf(RED "\nError\nWrong arguments!🙈" RESET);
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_complete));
	check_extension(&game, argv[1]);
	map_reading(&game, argv);
	character_valid(&game);
	if_walls(&game);
	valid_route(&game);
	init(&game);
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 33, 0, exit_point, &game);
	mlx_loop(game.mlxpointer);
}
