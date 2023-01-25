/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:49:34 by dgross            #+#    #+#             */
/*   Updated: 2023/01/25 23:07:45 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"

typedef struct s_map
{
	char	facing;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	char	**map;
	int		height;
	int		width;
}t_map;

typedef struct s_cub3d
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		**input;
	t_map		data;
}t_cub3d;

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void	print_error(char *reason);
void	init_cub3d(t_cub3d *cube);
void	init_mlx(t_cub3d *cube);
void	init_map(t_cub3d *cube);
void	events(void *param);

#endif