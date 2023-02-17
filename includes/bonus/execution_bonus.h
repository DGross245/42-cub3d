/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:11:00 by dgross            #+#    #+#             */
/*   Updated: 2023/02/17 16:16:45 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_BONUS_H
# define EXECUTION_BONUS_H

# include "cub3d_bonus.h"
# include "MLX42.h"

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void			calculator(t_cub3d *cube, t_cords *player);
void			paint_bg(t_cub3d	*cube, int x);
int				find_x_pos(t_cub3d *cube, mlx_texture_t *texture);
void			search_wall(t_cub3d *cube);
void			calc_dir(t_ray *ray, t_cords *player);
void			calc_wall(t_cub3d *cube);
void			init_textures(t_cub3d *cube);
mlx_texture_t	*get_wall_tex(t_cub3d *cube);
void			calc_player_dir(t_cords *player);
void			redraw(t_cub3d *cube);
unsigned int	hex_to_uint(char *hex);
void			painter(t_cub3d *cube, mlx_texture_t *texture, int x);
void			door(t_cub3d *cube, t_cords *player);
void			go_up(t_cords *player, t_cub3d *cube);
void			go_down(t_cords *player, t_cub3d *cube);
void			go_left(t_cords *player, t_cub3d *cube);
void			go_right(t_cords *player, t_cub3d *cube);
void			turn(t_cords *player, double angle);
void			mouse_position(t_cub3d *mlx, t_cords *player);
mlx_texture_t	*is_door(t_cub3d *cube, mlx_texture_t *wall_tex);

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

#endif