/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:29:30 by dgross            #+#    #+#             */
/*   Updated: 2023/02/11 16:48:50 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "execution.h"
#include "trash.h"
#include "libft.h" // ft_split ft_isdigit ft_ptrcnt

void	check_is_set(t_cub3d *cube)
{
	if (cube->data.east == NULL || cube->data.west == NULL
		|| cube->data.north == NULL || cube->data.south == NULL
		|| cube->f_set == 0 || cube->c_set == 0)
		print_error(cube, "missing identifier❗");
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
			get_path(cube, check);
			free_double((void **)check);
		}
		else if (cube->input[i][j] != '\0' && ft_isdigit(cube->input[i][j]))
		{
			check_is_set(cube);
			get_map(cube, &cube->data, &i);
		}
		i++;
	}
	init_textures(cube);
}

int	is_start_position(t_cub3d	*cube, int x, int y)
{
	char	typ;

	typ = cube->data.map[x][y];
	if (typ == 'N' || typ == 'S' || typ == 'W' || typ == 'E')
	{
		if (cube->player.facing != '\0')
			print_error(cube, "to many start positions ❗");
		cube->player.facing = typ;
		cube->player.xppos = x + 0.5;
		cube->player.yppos = y + 0.5;
		cube->data.map[x][y] = '0';
		calc_player_dir(&cube->player);
		return (1);
	}
	if (typ == '0')
		return (1);
	return (0);
}

void	check_surrounding(t_cub3d *cube, int x, int y)
{
	if (y == 0 || !cube->data.map[x + 1] || !cube->data.map[x - 1]
		|| !is_valid(cube->data.map[x][y - 1])
		|| !is_valid(cube->data.map[x][y + 1])
		|| !is_valid(cube->data.map[x - 1][y])
		|| !is_valid(cube->data.map[x + 1][y]))
		print_error(cube, "invalid map ❗");
}

void	check_map(t_cub3d *cube)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	cube->data.height = ft_ptrcnt(cube->data.map);
	while (cube->data.map[++x])
	{
		y = -1;
		while (cube->data.map[x][++y])
		{
			if (ft_isspace(cube->data.map[x][y]))
				;
			else if (x == 0 && cube->data.map[x][y] != '1')
				print_error(cube, "invalid map ❗");
			else if (x == cube->data.height && cube->data.map[x][y] != '1')
				print_error(cube, "invalid map ❗");
			else if (is_start_position(cube, x, y) && cube->data.map[x + 1])
				check_surrounding(cube, x, y);
			else if (cube->data.map[x][y] != '0' && cube->data.map[x][y] != '1'
				&& cube->data.map[x][y] != '2')
				print_error(cube, "invalid map ❗");
		}
	}
	is_player_set(cube);
}
