/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:06:55 by dgross            #+#    #+#             */
/*   Updated: 2023/02/07 14:26:03 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

#include <fcntl.h> // open
#include <stddef.h> // NULL
#include <stdio.h>

static void	check_colour_range(t_cub3d *cube, char **colour, char **str)
{
	int	i;
	int	nbr;

	i = -1;
	while (colour[++i])
	{
		nbr = ft_atoi(colour[i]);
		if (nbr < 0 || nbr > 255)
		{
			free_double((void **)colour);
			free_double((void **)str);
			print_error(cube, "wrong colour range");
		}
	}
}

static void	set_colour(t_cub3d *cube, char **colour, char **str)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(colour[0]);
	g = ft_atoi(colour[1]);
	b = ft_atoi(colour[2]);
	if (!ft_strcmp(str[0], "F"))
	{
		cube->data.floor = rgba_to_uint(r, g, b, 255);
		cube->f_set = 1;
	}
	else
	{
		cube->data.ceiling = rgba_to_uint(r, g, b, 255);
		cube->c_set = 1;
	}
}

void	get_colour(t_cub3d *cube, char **str)
{
	char	**colour;

	if (str[1] == NULL)
	{
		free_double((void **)str);
		print_error(cube, "colours not set ❗");
	}
	colour = ft_split(str[1], ',');
	if (ft_ptrcnt(colour) != 3)
	{
		free_double((void **)colour);
		free_double((void **)str);
		print_error(cube, "wrong colour ❗");
	}
	check_colour_range(cube, colour, str);
	set_colour(cube, colour, str);
	free_double((void **)colour);
}

void	get_path(t_cub3d *cube, char **str)
{
	if (str[1] == NULL)
	{
		free_double((void **)str);
		print_error(cube, "missing or wrong identifier ❗");
	}
	if (!ft_strcmp(str[0], "NO"))
		cube->data.north = gc_strdup(cube, str[1]);
	else if (!ft_strcmp(str[0], "SO"))
		cube->data.south = gc_strdup(cube, str[1]);
	else if (!ft_strcmp(str[0], "WE"))
		cube->data.west = gc_strdup(cube, str[1]);
	else if (!ft_strcmp(str[0], "EA"))
		cube->data.east = gc_strdup(cube, str[1]);
	else if (!ft_strcmp(str[0], "F") || !ft_strcmp(str[0], "C"))
		get_colour(cube, str);
	else
	{
		free_double((void **)str);
		print_error(cube, "missing or wrong identifier ❗");
	}
}

void	get_map(t_cub3d *cube, t_map *data, int *i)
{
	int	j;
	int	len;
	int	y;

	y = *i;
	len = 0;
	j = 0;
	while (cube->input[y] != NULL)
	{
		if (cube->input[y++][0] != '\0')
			len++;
		else
			print_error(cube, "invalid map ❗");
	}
	data->map = ft_calloc(len + 1, sizeof(char *));
	while (cube->input[(*i)])
		data->map[j++] = gc_strdup(cube, cube->input[(*i)++]);
	data->map[j] = NULL;
	pile_up(&cube->gc.dump, new_container(&cube->gc, data->map));
	(*i)--;
	check_map(cube);
}
