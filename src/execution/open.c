/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:13:26 by dna               #+#    #+#             */
/*   Updated: 2023/02/09 15:50:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "execution.h"

void	door(t_cub3d *cube, t_cords *player)
{
	double	tmp_x;
	double	tmp_y;

	if (cube->door == 2)
	{
		cube->door = 0;
		tmp_x = ((player->xppos) + player->xpdir * 0.08);
		tmp_y = ((player->yppos) + player->ypdir * 0.08);
		if (cube->data.map[(int)tmp_x - 1][(int)tmp_y] == '2')
			cube->data.map[(int)tmp_x - 1][(int)tmp_y] = '3';
		else if (cube->data.map[(int)tmp_x + 1][(int)tmp_y] == '2')
			cube->data.map[(int)tmp_x + 1][(int)tmp_y] = '3';
		else if (cube->data.map[(int)tmp_x - 1][(int)tmp_y] == '3')
			cube->data.map[(int)tmp_x - 1][(int)tmp_y] = '2';
		else if (cube->data.map[(int)tmp_x + 1][(int)tmp_y] == '3')
			cube->data.map[(int)tmp_x + 1][(int)tmp_y] = '2';
	}
	else
		cube->door++;
}
