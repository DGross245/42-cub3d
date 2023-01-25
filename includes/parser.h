/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:25:39 by dgross            #+#    #+#             */
/*   Updated: 2023/01/25 21:48:46 by dna              ###   ########.fr       */
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
void	get_map(t_map *data, t_cub3d *cube, int *i);
char	*to_hex(unsigned int nbr);
void	get_map(t_map *data, t_cub3d *cube, int *i);
void	check_map(t_map *data);
int		ft_isspace(int c);
char	*to_hex(unsigned int nbr);
int		is_valid(char c);

void	print_map(t_cub3d *cube);
void	print_data(t_map data);
#endif