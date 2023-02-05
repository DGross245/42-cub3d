/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:48:36 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 11:33:36 by dna              ###   ########.fr       */
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
	init_textures(&cube);
	calculator(&cube, &cube.player);
	mlx_loop_hook(cube.mlx, &events, &cube);
	mlx_loop(cube.mlx);
	mlx_terminate(cube.mlx);
	return (0);
}
