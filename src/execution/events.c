/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:47:35 by dgross            #+#    #+#             */
/*   Updated: 2024/05/17 23:34:10 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "MLX42.h"
#include "cub3d.h"

static void	go(t_cub3d *cube)
{
	if (mlx_is_key_down(cube->mlx, MLX_KEY_W)
		&& mlx_is_key_down(cube->mlx, MLX_KEY_LEFT_SHIFT))
		cube->mov_speed = 0.15;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_W))
		go_up(&cube->player, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_S))
		go_down(&cube->player, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_A))
		go_left(&cube->player, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_D))
		go_right(&cube->player, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
		turn(&cube->player, 0.1);
	else if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
		turn(&cube->player, -0.1);
}

void	events(void *param)
{
	t_cub3d	*cube;

	cube = (t_cub3d *)param;
	cube->mov_speed = 0.08;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cube->mlx);
	go(cube);
	redraw(cube);
}

void	redraw(t_cub3d *cube)
{
	mlx_delete_image(cube->mlx, cube->img);
	cube->img = mlx_new_image(cube->mlx, 1920, 1080);
	if (!cube->img)
		print_error(cube, "MLX IMG error");
	calculator(cube, &cube->player);
}
