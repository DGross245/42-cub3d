/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:27:26 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 20:57:12 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "cub3d.h"
# include "MLX42.h"

void			calculator(t_cub3d *cube, t_cords *player);
int				ft_abs(int x);
void			paint_bg(t_cub3d	*cube, int x);
int				find_wall(t_cub3d *cube, mlx_texture_t *texture);
void			dda(t_cub3d *cube);
void			calc_rest(t_cub3d *cube);
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
void			turn_left(t_cords *player);
void			turn_right(t_cords *player);

#endif