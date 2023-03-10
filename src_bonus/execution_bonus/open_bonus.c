/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:29:14 by dgross            #+#    #+#             */
/*   Updated: 2023/02/19 16:30:40 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d_bonus.h"

static void	replace_door(t_cub3d *cube, double tmp_x, double tmp_y)
{
	if (cube->data.map[(int)tmp_x - 1][(int)tmp_y] == '2')
		cube->data.map[(int)tmp_x - 1][(int)tmp_y] = '3';
	else if (cube->data.map[(int)tmp_x + 1][(int)tmp_y] == '2')
		cube->data.map[(int)tmp_x + 1][(int)tmp_y] = '3';
	else if (cube->data.map[(int)tmp_x - 1][(int)tmp_y] == '3')
		cube->data.map[(int)tmp_x - 1][(int)tmp_y] = '2';
	else if (cube->data.map[(int)tmp_x + 1][(int)tmp_y] == '3')
		cube->data.map[(int)tmp_x + 1][(int)tmp_y] = '2';
	else if (cube->data.map[(int)tmp_x][(int)tmp_y - 1] == '2')
		cube->data.map[(int)tmp_x][(int)tmp_y - 1] = '3';
	else if (cube->data.map[(int)tmp_x][(int)tmp_y + 1] == '2')
		cube->data.map[(int)tmp_x][(int)tmp_y + 1] = '3';
	else if (cube->data.map[(int)tmp_x][(int)tmp_y - 1] == '3')
		cube->data.map[(int)tmp_x][(int)tmp_y - 1] = '2';
	else if (cube->data.map[(int)tmp_x][(int)tmp_y + 1] == '3')
		cube->data.map[(int)tmp_x][(int)tmp_y + 1] = '2';
}

void	door(t_cub3d *cube, t_cords *player)
{
	double	tmp_x;
	double	tmp_y;

	if (cube->door == 2)
	{
		cube->door = 0;
		tmp_x = player->xppos + cube->mov_speed * player->xpdir;
		tmp_y = player->yppos + cube->mov_speed * player->ypdir;
		replace_door(cube, tmp_x, tmp_y);
	}
	else
		cube->door++;
}
