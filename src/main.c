/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:48:36 by dgross            #+#    #+#             */
/*   Updated: 2023/01/21 12:50:53 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

void	events(void *param)
{
	t_cub3d	*cube;

	cube = (t_cub3d *)param;
}

int	main(int argc, char **argv)
{
	t_cub3d	cube;

	init_cub3d(&cube);
	parser(&cube, argc, argv);
	//calculator();
	//painter();
	mlx_terminate(cube.mlx);
	//mlx_loop_hook(cube.mlx, &events, &cube);
	//mlx_loop(cube.mlx);
	mlx_terminate(cube.mlx);
	//gc_shit
	return (0);
}
