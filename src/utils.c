/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:00:16 by dna               #+#    #+#             */
/*   Updated: 2023/02/06 13:28:54 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdlib.h> // malloc

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

char	*to_hex(unsigned int nbr)
{
	char	*hex;
	char	*result;
	int		i;

	i = 0;
	hex = "0123456789ABCDEF";
	result = malloc(sizeof(char) * 8);
	while (nbr)
	{
		result[i++] = hex[nbr % 16];
		nbr /= 16;
	}
	result[i] = '\0';
	return (result);
}

int	is_valid(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0' || c == '1')
		return (1);
	else
		return (0);
}

void	is_player_set(t_cub3d *cube)
{
	if (cube->player.facing == '\0')
		print_error(cube, "missing player's spawn & orientation ❗");
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
