/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:29:30 by dgross            #+#    #+#             */
/*   Updated: 2023/01/26 12:13:22 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "trash.h"

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
}

int	is_start_position(t_map *data, int y, int x)
{
	char	typ;

	typ = data->map[y][x];
	if (typ == 'N' || typ == 'S' || typ == 'W' || typ == 'E')
	{
		if (data->facing != '\0')
			print_error("to many start positions ❗");
		data->facing = typ;
		return (1);
	}
	if (typ == '0')
		return (1);
	return (0);
}

void	check_surrounding(t_map *data, int y, int x)
{
	if (x == 0 || !data->map[y + 1] || !data->map[y - 1]
		|| !is_valid(data->map[y][x - 1]) || !is_valid(data->map[y][x + 1])
		|| !is_valid(data->map[y - 1][x]) || !is_valid(data->map[y + 1][x]))
		print_error("invalid map ❗");
}

int	is_valid(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0' || c == '1')
		return (1);
	else
		return (0);
}

void	check_map(t_map *data)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	data->height = ft_ptrcnt(data->map);
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (ft_isspace(data->map[y][x]))
				;
			else if (y == 0 && data->map[y][x] != '1')
				print_error("invalid map ❗");
			else if (y == data->height && data->map[y][x] != '1')
				print_error("invalid map ❗");
			else if (is_start_position(data, y, x) && data->map[y + 1])
				check_surrounding(data, y, x);
			else if (data->map[y][x] != '0' && data->map[y][x] != '1')
				print_error("invalid map ❗");
		}
	}	
}
