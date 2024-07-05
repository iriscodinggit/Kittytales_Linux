/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorswalls_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:35:59 by irlozano          #+#    #+#             */
/*   Updated: 2024/06/26 14:15:49 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_linei.h"
#include "ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

void	check_extension(t_complete *game, char *path)
{
	int		len;
	char	*expected_extension;

	expected_extension = ".ber";
	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, expected_extension, 4) != 0)
	{
		ft_printf(RED "\nError\nMap's extension must be \".ber\"🙈" RESET);
		exit_point(game);
	}
}

int	horizontalwall(t_complete *game)
{
	int	x;

	x = 0;
	while (x < game->widthmap)
	{
		if (!(game->map[0][x] == '1'
			&& game->map[game->heightmap - 1][x] == '1'))
			return (0);
		x++;
	}
	return (1);
}

int	verticalwall(t_complete *game)
{
	int	y;

	y = 0;
	while (y < game->heightmap)
	{
		if (!(game->map[y][0] == '1'
			&& game->map[y][game->widthmap - 1] == '1'))
			return (0);
		y++;
	}
	return (1);
}

void	if_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		ft_printf(RED "\nError\n🚧 Oh, crumbs!" RESET);
		ft_printf(RED "The map is not surrounded by walls! 🚧\n" RESET);
		exit_point(game);
	}
}
