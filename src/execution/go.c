/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:44:34 by dna               #+#    #+#             */
/*   Updated: 2023/02/08 10:27:54 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "MLX42.h"
#include "cub3d.h"
#include "macros.h"
#include <math.h>

void	go_up(t_cords *player, t_cub3d *cube)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->xppos + player->xpdir * 0.08;
	tmp_y = player->yppos + player->ypdir * 0.08;
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

	tmp_x = player->xppos - player->xpdir * 0.08;
	tmp_y = player->yppos - player->ypdir * 0.08;
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

	tmp_x = player->xppos - player->ypdir * 0.08;
	tmp_y = player->yppos + player->xpdir * 0.08;
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

	tmp_x = player->xppos + player->ypdir * 0.08;
	tmp_y = player->yppos - player->xpdir * 0.08;
	if (cube->data.map[(int)tmp_x][(int)tmp_y] == '0'
		|| cube->data.map[(int)tmp_x][(int)tmp_y] == '3')
	{
		player->xppos = tmp_x;
		player->yppos = tmp_y;
	}
}
