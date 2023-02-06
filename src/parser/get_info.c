/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:06:55 by dgross            #+#    #+#             */
/*   Updated: 2023/02/06 13:25:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

#include <fcntl.h> // open
#include <stddef.h> // NULL
#include <stdio.h>

static unsigned long	rgba_to_uint(int r, int g, int b, int a)
{
	return (((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) \
			+ (a & 0xff));
}

static void	check_colour_range(t_cub3d *cube, char **str)
{
	int	i;
	int	nbr;

	i = 0;
	while (str[++i])
	{
		nbr = ft_atoi(str[i]);
		if (nbr < 0 || nbr > 255)
			print_error(cube, "wrong colour range");
	}
}

void	get_colour(t_cub3d *cube, char **str)
{
	char	**colour;
	int		r;
	int		g;
	int		b;

	if (str[1] == NULL)
		print_error(cube, "colours not set ❗");
	colour = ft_split(str[1], ',');
	if (ft_ptrcnt(colour) != 3)
		print_error(cube, "wrong colour ❗");
	check_colour_range(cube, colour);
	r = ft_atoi(colour[0]);
	g = ft_atoi(colour[1]);
	b = ft_atoi(colour[2]);
	if (!ft_strcmp(str[0], "F"))
		cube->data.floor = rgba_to_uint(r, g, b, 255);
	else
		cube->data.ceiling = rgba_to_uint(r, g, b, 255);
}

void	get_path(t_cub3d *cube, char **str)
{
	if (!ft_strcmp(str[0], "NO"))
		cube->data.north = ft_strdup(str[1]);
	else if (!ft_strcmp(str[0], "SO"))
		cube->data.south = ft_strdup(str[1]);
	else if (!ft_strcmp(str[0], "WE"))
		cube->data.west = ft_strdup(str[1]);
	else if (!ft_strcmp(str[0], "EA"))
		cube->data.east = ft_strdup(str[1]);
	else if (!ft_strcmp(str[0], "F") || !ft_strcmp(str[0], "C"))
		get_colour(cube, str);
	else
		print_error(cube, "missing or wrong identifier ❗");
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
		data->map[j++] = ft_strdup(cube->input[(*i)++]);
	data->map[j] = NULL;
	(*i)--;
	check_map(cube);
}
