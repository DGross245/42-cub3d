/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:28:36 by dgross            #+#    #+#             */
/*   Updated: 2023/02/10 13:29:04 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d_bonus.h"

void	go_up(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos + player->xpdir * cube->mov_speed;
	tmp_y = player->yppos + player->ypdir * cube->mov_speed;
	if (cube->data.map[(int)tmp_x][(int)tmp_y] == '0'
		|| cube->data.map[(int)tmp_x][(int)tmp_y] == '3')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}

void	go_down(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos - player->xpdir * cube->mov_speed;
	tmp_y = player->yppos - player->ypdir * cube->mov_speed;
	if (cube->data.map[(int)tmp_x][(int)tmp_y] == '0'
		|| cube->data.map[(int)tmp_x][(int)tmp_y] == '3')
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
	if (cube->data.map[(int)tmp_x][(int)tmp_y] == '0'
		|| cube->data.map[(int)tmp_x][(int)tmp_y] == '3')
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
	if (cube->data.map[(int)tmp_x][(int)tmp_y] == '0'
		|| cube->data.map[(int)tmp_x][(int)tmp_y] == '3')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}
