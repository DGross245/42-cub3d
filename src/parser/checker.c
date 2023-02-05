/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:29:30 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 20:49:57 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "execution.h"
#include "libft.h"
#include "trash.h"
#include <stdio.h>

void	check_is_set(t_map *data)
{
	if (data->ceiling[0] == '\0' || data->floor[0] == '\0' || data->east == NULL
		|| data->west == NULL || data->north == NULL || data->south == NULL)
		print_error("missing identifier❗");
}

void	check_input(t_cub3d *cube)
{
	char	**check;
	int		i;
	int		j;

	i = 0;
	check = NULL;
	while (cube->input[i] != NULL)
	{
		j = 0;
		while (cube->input[i][j] != '\0' && ft_isspace(cube->input[i][j]))
			j++;
		if (cube->input[i][j] != '\0' && !ft_isdigit(cube->input[i][j]))
		{
			check = ft_split(cube->input[i], ' ');
			get_path(&cube->data, check);
			free_double((void **)check);
		}
		else if (cube->input[i][j] != '\0' && ft_isdigit(cube->input[i][j]))
		{
			check_is_set(&cube->data);
			get_map(&cube->data, cube, &i);
		}
		i++;
	}
	init_textures(cube);
}

int	is_start_position(t_map *data, t_cords *plaxer, int x, int y)
{
	char	txp;

	txp = data->map[x][y];
	if (txp == 'N' || txp == 'S' || txp == 'W' || txp == 'E')
	{
		if (plaxer->facing != '\0')
			print_error("to manx start positions ❗");
		plaxer->facing = txp;
		plaxer->xppos = x + 0.5;
		plaxer->yppos = y + 0.5;
		data->map[x][y] = '0';
		calc_player_dir(plaxer);
		return (1);
	}
	if (txp == '0')
		return (1);
	return (0);
}

void	check_surrounding(t_map *data, int x, int y)
{
	if (y == 0 || !data->map[x + 1] || !data->map[x - 1]
		|| !is_valid(data->map[x][y - 1]) || !is_valid(data->map[x][y + 1])
		|| !is_valid(data->map[x - 1][y]) || !is_valid(data->map[x + 1][y]))
		print_error("invalid map ❗");
}

void	check_map(t_map *data, t_cords *plaxer)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	data->height = ft_ptrcnt(data->map);
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			if (ft_isspace(data->map[x][y]))
				;
			else if (x == 0 && data->map[x][y] != '1')
				print_error("invalid map ❗");
			else if (x == data->height && data->map[x][y] != '1')
				print_error("invalid map ❗");
			else if (is_start_position(data, plaxer, x, y) && data->map[x + 1])
				check_surrounding(data, x, y);
			else if (data->map[x][y] != '0' && data->map[x][y] != '1')
				print_error("invalid map ❗");
		}
	}
	is_player_set(plaxer);
}
