/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:30:52 by dgross            #+#    #+#             */
/*   Updated: 2023/02/10 13:33:57 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "MLX42.h"
#include "libft.h" // ft_strlen

#include <unistd.h> // write
#include <stdlib.h> // exit

void	print_error(t_cub3d *cube, char *reason)
{
	write(2, "❌ ERROR: ", 11);
	write(2, reason, ft_strlen(reason));
	write(2, "\n", 1);
	nuke_trash(cube);
	mlx_terminate(cube->mlx);
	exit(1);
}
