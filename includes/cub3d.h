/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:49:34 by dgross            #+#    #+#             */
/*   Updated: 2023/02/01 10:44:41 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"

typedef struct s_map
{
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

typedef struct s_cords
{
	char	facing;
	float	xppos;
	float	yppos;
	float	xpdir;
	float	ypdir;
}t_cords;

typedef struct s_points
{
	float	rayx;
	float	rayy;
	float	raydirx;
	float	raydiry;
	float	camx;
}t_points;

typedef struct s_cub3d
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		**input;
	t_map		data;
	t_cords		player;
	t_points	dot;
}t_cub3d;

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void	print_error(char *reason);
void	init_cub3d(t_cub3d *cube);
void	init_mlx(t_cub3d *cube);
void	init_map(t_cub3d *cube);
void	init_player(t_cub3d *cube);
void	init_cam(t_cub3d *cube);
void	events(void *param);

#endif