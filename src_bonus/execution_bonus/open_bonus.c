/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:29:14 by dgross            #+#    #+#             */
/*   Updated: 2023/02/11 12:07:12 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d_bonus.h"

void	door(t_cub3d *cube, t_cords *player)
{
	double	tmp_x;
	double	tmp_y;

	if (cube->door == 2)
	{
		cube->door = 0;
		tmp_x = player->xppos + cube->mov_speed * player->xpdir;
		tmp_y = player->yppos + cube->mov_speed * player->ypdir;
		if (check_wall_hit(cube, tmp_x - 1, tmp_y) == '2')
			cube->data.map[(int)tmp_x - 1][(int)tmp_y] = '3';
		else if (check_wall_hit(cube, tmp_x + 1, tmp_y) == '2')
			cube->data.map[(int)tmp_x + 1][(int)tmp_y] = '3';
		else if (check_wall_hit(cube, tmp_x - 1, tmp_y) == '3')
			cube->data.map[(int)tmp_x - 1][(int)tmp_y] = '2';
		else if (check_wall_hit(cube, tmp_x + 1, tmp_y) == '3')
			cube->data.map[(int)tmp_x + 1][(int)tmp_y] = '2';
	}
	else
		cube->door++;
}
