/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:49:34 by dgross            #+#    #+#             */
/*   Updated: 2023/01/24 13:55:42 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"

# define HEIGHT				1080
# define WIDTH				1920

typedef struct s_map
{
	int		north;
	int		south;
	int		west;
	int		east;
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

# define ERROR -1

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void	print_error(char *reason);
void	init_cub3d(t_cub3d *cube);
void	init_mlx(t_cub3d *cube);
void	init_map(t_cub3d *cube);
void	events(void *param);

#endif