/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:25:39 by dgross            #+#    #+#             */
/*   Updated: 2023/02/10 13:12:19 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void			parser(t_cub3d *cube, int argc, char **argv);
void			reader(t_cub3d *cube, int fd);
void			check_input(t_cub3d *cube);
int				ft_isspace(int c);
void			get_path(t_cub3d *cube, char **str);
void			get_colour(t_cub3d *cube, char **str);
void			get_map(t_cub3d *cube, t_map *data, int *i);
void			get_map(t_cub3d *cube, t_map *data, int *i);
void			check_map(t_cub3d *cube);
int				ft_isspace(int c);
int				is_valid(char c);
int				is_start_position(t_cub3d *cube, int y, int x);
void			is_player_set(t_cub3d *cube);
unsigned long	rgba_to_uint(int r, int g, int b, int a);

//  .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//:::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.
//'      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

#endif