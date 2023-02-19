/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:02:16 by dna               #+#    #+#             */
/*   Updated: 2023/02/19 13:52:17 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"

#include <math.h> // con sin

void	turn(t_cords *player, double angle)
{
	double	tmp_dirx;
	double	tmp_plane_x;
	double	sin_a;
	double	cos_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	tmp_dirx = player->xpdir;
	tmp_plane_x = player->plane_x;
	player->xpdir = player->xpdir * cos_a - player->ypdir * sin_a;
	player->ypdir = tmp_dirx * sin_a + player->ypdir * cos_a;
	player->plane_x = player->plane_x * cos_a - player->plane_y * sin_a;
	player->plane_y = tmp_plane_x * sin_a + player->plane_y * cos_a;
}
