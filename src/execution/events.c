/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:47:35 by dna               #+#    #+#             */
/*   Updated: 2023/02/09 15:12:06 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "MLX42.h"
#include "cub3d.h"
#include "macros.h"

void	events(void *param)
{
	t_cub3d	*cube;

	cube = (t_cub3d *)param;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cube->mlx);
	if ((mlx_is_key_down(cube->mlx, MLX_KEY_W)
			|| mlx_is_key_down(cube->mlx, MLX_KEY_UP)))
		go_up(&cube->player, cube);
	if ((mlx_is_key_down(cube->mlx, MLX_KEY_S)
			|| mlx_is_key_down(cube->mlx, MLX_KEY_DOWN)))
		go_down(&cube->player, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_A)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
		go_left(&cube->player, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_D)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
		go_right(&cube->player, cube);
	else if (mlx_is_key_down(cube->mlx, MLX_KEY_E))
		door(cube, &cube->player);
	mouse_position(cube, &cube->player);
	redraw(cube);
}

void	redraw(t_cub3d *cube)
{
	mlx_delete_image(cube->mlx, cube->img);
	cube->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->img)
		print_error(cube, "MLX IMG error");
	calculator(cube, &cube->player);
}
