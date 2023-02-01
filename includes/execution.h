/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:27:26 by dgross            #+#    #+#             */
/*   Updated: 2023/02/01 17:13:31 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "cub3d.h"

void	calculator(t_cub3d *cube, t_cords *player);
int		ft_abs(int x);
void	painter(t_cub3d *cube, int wall_dist);
int		find_wall(t_cub3d *cube);
#endif