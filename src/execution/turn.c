/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:02:16 by dna               #+#    #+#             */
/*   Updated: 2023/02/05 10:02:33 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "MLX42.h"
#include "cub3d.h"
#include "macros.h"
#include <math.h>

void	turn_right(t_cords *player)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = player->xpdir;
	tmp_plane_x = player->plane_x;
	player->xpdir = player->xpdir * cos(-0.2) - player->ypdir * sin(-0.2);
	player->ypdir = tmp_dir_x * sin(-0.2) + player->ypdir * cos(-0.2);
	player->plane_x = player->plane_x * cos(-0.2) - player->plane_y * sin(-0.2);
	player->plane_y = tmp_plane_x * sin(-0.2) + player->plane_y * cos(-0.2);
}

void	turn_left(t_cords *player)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = player->xpdir;
	tmp_plane_x = player->plane_x;
	player->xpdir = player->xpdir * cos(0.2) - player->ypdir * sin(0.2);
	player->ypdir = tmp_dir_x * sin(0.2) + player->ypdir * cos(0.2);
	player->plane_x = player->plane_x * cos(0.2) - player->plane_y * sin(0.2);
	player->plane_y = tmp_plane_x * sin(0.2) + player->plane_y * cos(0.2);
}