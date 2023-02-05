/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:27:26 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 11:42:44 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "cub3d.h"
# include "MLX42.h"

void	calculator(t_cub3d *cube, t_cords *player);
int		ft_abs(int x);
void	paint_bg(t_cub3d	*cube, int x);
double	find_wall(t_cub3d *cube, double wall_dist);
double	calc_wall(t_cub3d *cube);
void	calc_rest(t_cub3d *cube, mlx_texture_t *tex, int x);
void	init_textures(t_cub3d *cube);
int		get_wall_tex(t_cub3d *cube);
void	calc_player_dir(t_cords *player);
void	redraw(t_cub3d *cube);

void	go_up(t_cords *player, t_cub3d *cube);
void	go_down(t_cords *player, t_cub3d *cube);
void	go_left(t_cords *player, t_cub3d *cube);
void	go_right(t_cords *player, t_cub3d *cube);
void	turn_left(t_cords *player);
void	turn_right(t_cords *player);

#endif