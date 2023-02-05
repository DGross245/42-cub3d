/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:06:55 by dgross            #+#    #+#             */
/*   Updated: 2023/02/05 23:48:24 by dna              ###   ########.fr       */
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

static void	check_colour_range(char **str)
{
	int	i;
	int	nbr;

	i = 0;
	while (str[++i])
	{
		nbr = ft_atoi(str[i]);
		if (nbr < 0 || nbr > 255)
			print_error("wrong colour range");
	}
}

void	get_colour(t_map *data, char **str)
{
	char	**colour;
	int		r;
	int		g;
	int		b;

	if (str[1] == NULL)
		print_error("colours not set ❗");
	colour = ft_split(str[1], ',');
	if (ft_ptrcnt(colour) != 3)
		print_error("wrong colour ❗");
	check_colour_range(colour);
	r = ft_atoi(colour[0]);
	g = ft_atoi(colour[1]);
	b = ft_atoi(colour[2]);
	if (!ft_strcmp(str[0], "F"))
		data->floor = rgba_to_uint(r, g, b, 255);
	else
		data->ceiling = rgba_to_uint(r, g, b, 255);
}

void	get_path(t_map *data, char **str)
{
	if (!ft_strcmp(str[0], "NO"))
		data->north = ft_strdup(str[1]);
	else if (!ft_strcmp(str[0], "SO"))
		data->south = ft_strdup(str[1]);
	else if (!ft_strcmp(str[0], "WE"))
		data->west = ft_strdup(str[1]);
	else if (!ft_strcmp(str[0], "EA"))
		data->east = ft_strdup(str[1]);
	else if (!ft_strcmp(str[0], "F") || !ft_strcmp(str[0], "C"))
		get_colour(data, str);
	else
		print_error("missing or wrong identifier ❗");
}

void	get_map(t_map *data, t_cub3d *cube, int *i)
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
			print_error("invalid map ❗");
	}
	data->map = ft_calloc(len + 1, sizeof(char *));
	while (cube->input[(*i)])
		data->map[j++] = ft_strdup(cube->input[(*i)++]);
	data->map[j] = NULL;
	(*i)--;
	check_map(data, &cube->player);
}
