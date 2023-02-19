/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:27:26 by dgross            #+#    #+#             */
/*   Updated: 2023/02/19 12:31:33 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "cub3d.h"
# include "MLX42.h"

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void			calculator(t_cub3d *cube, t_cords *player);
void			paint_bg(t_cub3d	*cube, int x);
int				find_x_pos(t_cub3d *cube, mlx_texture_t *texture);
void			search_wall(t_cub3d *cube);
void			calc_dir(t_ray	*ray, t_cords *player);
void			calc_wall(t_cub3d *cube);
void			init_textures(t_cub3d *cube);
mlx_texture_t	*get_wall_tex(t_cub3d *cube);
void			calc_player_dir(t_cords *player);
void			redraw(t_cub3d *cube);
unsigned int	hex_to_uint(char *hex);
void			painter(t_cub3d *cube, mlx_texture_t *texture, int x);
void			go_up(t_cords *player, t_cub3d *cube);
void			go_down(t_cords *player, t_cub3d *cube);
void			go_left(t_cords *player, t_cub3d *cube);
void			go_right(t_cords *player, t_cub3d *cube);
void			turn(t_cords *player, double angle);

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

#endif