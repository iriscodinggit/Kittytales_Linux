/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:54:20 by irlozano          #+#    #+#             */
/*   Updated: 2024/06/27 16:11:48 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temporary)
	{
		ft_printf(RED "\nError\nOh, oh! 🙈\nMemory allocation failed!\n" RESET);
		exit_point(game);
	}
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

void	map_rectangular(t_complete *game)
{
	int	heightmap;
	int	line_length;

	heightmap = game->heightmap;
	while (heightmap--)
	{
		line_length = width_of_map(game->map[heightmap]);
		if (line_length != game->widthmap)
		{
			ft_printf(RED "\nError\nOh, oh! 🙈\nNot rectangular!\n" RESET);
			exit_point(game);
		}
	}
}

void	map_too_big(t_complete *game)
{
	if (game->widthmap > 100 || game->heightmap > 100)
	{
		ft_printf(RED "\nError\nOh, oh! 🙈\nToo big!\n" RESET);
		exit_point(game);
	}
}

int	map_reading(t_complete *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	readmap = get_next_line(game->fd);
	if (!readmap)
	{
		ft_printf(RED "\nError\nOh, oh! 🙈\nThe map is empty!\n" RESET);
		close (game->fd);
		exit_point(game);
	}
	while (add_line(game, readmap))
	{
		readmap = NULL;
		readmap = get_next_line(game->fd);
	}
	if (readmap)
		free(readmap);
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	map_rectangular(game);
	map_too_big(game);
	return (1);
}
