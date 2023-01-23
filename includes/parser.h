/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:25:39 by dgross            #+#    #+#             */
/*   Updated: 2023/01/23 21:07:28 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

void	parser(t_cub3d *cube, int argc, char **argv);
void	reader(t_cub3d *cube, int fd);
void	check_input(t_cub3d *cube);
int		ft_isspace(int c);
void	get_path(t_map *data, char **str);
void	get_colour(t_map **data, char **str);

void	print_map(t_cub3d *cube);
void	print_data(t_map data);
#endif