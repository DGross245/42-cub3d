/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:44:34 by dna               #+#    #+#             */
/*   Updated: 2023/02/11 08:45:03 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include "libft.h"

#include <math.h>
#include <stdio.h>

void	go_up(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;
	int		x;
	int		y;

	tmp_x = player->xppos + cube->mov_speed * player->xpdir;
	tmp_y = player->yppos + cube->mov_speed * player->ypdir;
	x = round(tmp_x);
	y = round(tmp_y);
	if (x >= 0 && x < (int)ft_strlen(cube->data.map[x]) && y >= 0 && y < cube->data.height)
	{
		if (cube->data.map[x][y] == '0')
		{
			player->xppos = tmp_x;
			player->yppos = tmp_y;
		}	
	}
}

void	go_down(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos - player->xpdir * cube->mov_speed;
	tmp_y = player->yppos - player->ypdir * cube->mov_speed;
	if (cube->data.map[(int)tmp_x][(int)tmp_y] == '0')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}

void	go_left(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos - player->ypdir * cube->mov_speed;
	tmp_y = player->yppos + player->xpdir * cube->mov_speed;
	if (cube->data.map[(int)tmp_x][(int)tmp_y] == '0')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}

void	go_right(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos + player->ypdir * cube->mov_speed;
	tmp_y = player->yppos - player->xpdir * cube->mov_speed;
	if (cube->data.map[(int)tmp_x][(int)tmp_y] == '0')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}
