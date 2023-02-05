/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:49:34 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 23:34:27 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"

typedef struct s_map
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	unsigned int	floor;
	unsigned int	ceiling;
	char			**map;
	int				height;
	int				width;
}t_map;

typedef struct s_cords
{
	char	facing;
	double	xppos;
	double	yppos;
	double	xpdir;
	double	ypdir;
	double	plane_x;
	double	plane_y;
}t_cords;

typedef struct s_tex
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}t_tex;

typedef struct s_ray
{
	double	rayx;
	double	rayy;
	double	raydirx;
	double	raydiry;
	double	camx;
	double	deltadisx;
	double	deltadisy;
	int		map_x;
	int		map_y;
	double	sidedis_x;
	double	sidedis_y;
	int		wall_hit;
	double	stepx;
	double	stepy;
	int		wall_side;
	double	wall_dist;
	int		start;
	int		end;
	double	lheight;
}t_ray;

typedef struct s_cub3d
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_tex			tex;
	char			**input;
	t_map			data;
	t_cords			player;
	t_ray			ray;
	int				tmp_x;
	int				tmp_y;
}t_cub3d;

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void	print_error(char *reason);
void	init_cub3d(t_cub3d *cube);
void	init_mlx(t_cub3d *cube);
void	init_map(t_cub3d *cube);
void	init_player(t_cub3d *cube);
void	events(void *param);

#endif