/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:25:39 by dgross            #+#    #+#             */
/*   Updated: 2023/01/21 15:38:56 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

void	parser(t_cub3d *cube, int argc, char **argv);
void	reader(t_cub3d *cube, int fd);
void	check_input(t_cub3d *cube);


void	print_map(t_cub3d *cube);

#endif