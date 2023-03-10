/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:30:56 by dgross            #+#    #+#             */
/*   Updated: 2023/02/19 13:23:50 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "parser_bonus.h"
#include "execution_bonus.h"
#include "MLX42.h"

int	main(int argc, char **argv)
{
	t_cub3d	cube;

	init_cub3d(&cube);
	parser(&cube, argc, argv);
	init_textures(&cube);
	calculator(&cube, &cube.player);
	mlx_loop_hook(cube.mlx, &events, &cube);
	mlx_loop(cube.mlx);
	mlx_terminate(cube.mlx);
	nuke_trash(&cube);
	return (0);
}
