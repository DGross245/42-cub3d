/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:32:06 by dgross            #+#    #+#             */
/*   Updated: 2023/01/31 14:12:11 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	calc_player_dir(t_cords *player)
{
	if (player->facing == 'N')
		player->xpdir = 0;
	else if (player->facing == 'E')
	{
		player->xpdir = 1;
		player->ypdir = 0;
	}
	else if (player->facing == 'S')
	{
		player->xpdir = 0;
		player->ypdir = 1;
	}
	else if (player->facing == 'W')
		player->ypdir = 0;
}
