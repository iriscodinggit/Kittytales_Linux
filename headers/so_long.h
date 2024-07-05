/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:13:52 by irlozano          #+#    #+#             */
/*   Updated: 2024/06/28 14:13:54 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h> //para el write de gnl
# include <stdio.h> //para perror
# include <fcntl.h> //para open y close
# include "get_next_linei.h"
# include "../mlx_linux/mlx.h"

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		coinparse;
	int		coincount;
	int		exitparse;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	char	**map;
	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int		exit_point(t_complete *game);
int		map_reading(t_complete *game, char **argv);
int		controls_working(int command, t_complete *game);
void	valid_route(t_complete *game);
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
void	character_valid(t_complete *game);
void	if_walls(t_complete *game);
void	check_extension(t_complete *game, char *path);
int		right_move(t_complete *game, int i, int j);
int		keyboard_w(t_complete *game, int movement);
int		keyboard_s(t_complete *game, int movement);
int		keyboard_d(t_complete *game, int movement);
int		keyboard_a(t_complete *game, int movement);

# define RED "\033[0;31m" 
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define PINK "\033[38;5;218m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;97m"
# define RESET "\033[0m"

#endif
