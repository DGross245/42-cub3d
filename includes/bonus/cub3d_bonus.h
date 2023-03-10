/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:10:58 by dgross            #+#    #+#             */
/*   Updated: 2023/02/23 12:51:40 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "MLX42.h"
# include "trash_bonus.h"

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
	char			*door;
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
	mlx_texture_t	*door;
	mlx_texture_t	*door_open;
}t_tex;

typedef struct s_ray
{
	double	rayx;
	double	rayy;
	double	raydirx;
	double	raydiry;
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
	t_gc			gc;
	int				tmp_x;
	int				tmp_y;
	int				c_set;
	int				f_set;
	int				door;
	float			mov_speed;
}t_cub3d;

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void	print_error(t_cub3d *cube, char *reason);
void	init_cub3d(t_cub3d *cube);
void	init_map(t_cub3d *cube);
void	init_player(t_cub3d *cube);
void	events(void *param);
void	nuke_trash(t_cub3d	*cube);
char	*gc_strdup(t_cub3d *cube, const char *s1);
char	check_wall_hit(t_cub3d *cube, double tmp_x, double tmp_y);
void	check_png(t_cub3d *cube);
char	**ft_split_2(char const *s, char *chars);

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

#endif