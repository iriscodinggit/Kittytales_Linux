/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:45:12 by irlozano          #+#    #+#             */
/*   Updated: 2024/06/26 13:35:13 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	controls_working(int command, t_complete *game)
{
	int	works;

	works = 0;
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
		adding_in_graphics(game);
	return (1);
}
