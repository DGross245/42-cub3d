/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:48:36 by dgross            #+#    #+#             */
/*   Updated: 2023/02/01 14:11:08 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "execution.h"

int	main(int argc, char **argv)
{
	t_cub3d	cube;

	init_cub3d(&cube);
	parser(&cube, argc, argv);
	calculator(&cube, &cube.player);
	mlx_image_to_window(cube.mlx, cube.img, 0, 0);
	mlx_loop_hook(cube.mlx, &events, &cube);
	mlx_loop(cube.mlx);
	mlx_terminate(cube.mlx);
	return (0);
}
