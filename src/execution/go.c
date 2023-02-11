/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:44:34 by dna               #+#    #+#             */
/*   Updated: 2023/02/11 09:53:36 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include "libft.h"

static char	check_wall_hit(t_cub3d *cube, double tmp_x, double tmp_y)
{
	if (cube->data.map[(int)(tmp_x + 0.2)][(int)(tmp_y + 0.2)] == '0' &&
		cube->data.map[(int)(tmp_x - 0.2)][(int)(tmp_y - 0.2)] == '0' &&
		cube->data.map[(int)(tmp_x - 0.2)][(int)(tmp_y + 0.2)] == '0' &&
		cube->data.map[(int)(tmp_x + 0.2)][(int)(tmp_y - 0.2)] == '0')
		return ('0');
	else
		return ('1');
}

void	go_up(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos + cube->mov_speed * player->xpdir;
	tmp_y = player->yppos + cube->mov_speed * player->ypdir;
	if (check_wall_hit(cube, tmp_x, tmp_y) == '0')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}

void	go_down(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos - cube->mov_speed * player->xpdir;
	tmp_y = player->yppos - cube->mov_speed * player->ypdir;
	if (check_wall_hit(cube, tmp_x, tmp_y) == '0')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}

void	go_left(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos - cube->mov_speed * player->ypdir;
	tmp_y = player->yppos + cube->mov_speed * player->xpdir;
	if (check_wall_hit(cube, tmp_x, tmp_y) == '0')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}

void	go_right(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos + cube->mov_speed * player->ypdir;
	tmp_y = player->yppos - cube->mov_speed * player->xpdir;
	if (check_wall_hit(cube, tmp_x, tmp_y) == '0')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}

