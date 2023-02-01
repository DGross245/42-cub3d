/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:32:06 by dgross            #+#    #+#             */
/*   Updated: 2023/02/01 11:50:54 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "cub3d.h"

void	calc_player_dir(t_cords *player)
{
	if (player->facing == 'N')
		player->xpdir = 0;
	else if (player->facing == 'E')
	{
		player->xpdir = 1;
		player->ypdir = 0;
	}
	else if (player->facing == 'S')
	{
		player->xpdir = 0;
		player->ypdir = 1;
	}
	else if (player->facing == 'W')
		player->ypdir = 0;
}

void	set_ray_data(t_cub3d *cube, t_cords *player, int x)
{
	cube->dot.camx = 2 * x / cube->data.width - 1;
	cube->dot.raydirx = player->xpdir * 0 * cube->dot.camx;
	cube->dot.raydiry = player->ypdir * 0.66 * cube->dot.camx;
}

void	calculator(t_cub3d *cube, t_cords *player)
{
	int	x;

	x = -1;
	while (++x < cube->data.width)
	{
		set_ray_data(cube, player, x);
	}
}
