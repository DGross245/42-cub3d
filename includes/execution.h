/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:27:26 by dgross            #+#    #+#             */
/*   Updated: 2023/01/31 16:37:33 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "cub3d.h"

// gucken ob man doch vllt mit doubles arbeitet anstatt floats
typedef struct s_cords
{
	char	facing;
	float	xppos;
	float	yppos;
	float	xpdir;
	float	ypdir;
}t_cords;

typedef struct s_cam
{
	/* data */
}t_cam;

void	calculator(t_cub3d *cube, t_cords *player);

#endif