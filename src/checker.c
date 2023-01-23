/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:29:30 by dgross            #+#    #+#             */
/*   Updated: 2023/01/23 22:32:26 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "trash.h"

#include <fcntl.h> // open
#include <stdlib.h> // malloc
#include <stdio.h>

// z.46 verursacht zwischen durch einen segfault. Nochmal nachgucken was da los ist
void	map_checker(t_map *data, char **map, int *i)
{
	(void)data;
	(void)map;
	(void)i;
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
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
		else if (ft_isdigit(cube->input[i][j]))
			map_checker(&cube->data, cube->input, &i);
		i++;
	}
	print_data(cube->data);
}

void	get_path(t_map *data, char **str)
{
	if (!ft_strcmp(str[0], "NO"))
		data->north = open(str[1], O_RDONLY);
	else if (!ft_strcmp(str[0], "SO"))
		data->south = open(str[1], O_RDONLY);
	else if (!ft_strcmp(str[0], "WE"))
		data->west = open(str[1], O_RDONLY);
	else if (!ft_strcmp(str[0], "EA"))
		data->east = open(str[1], O_RDONLY);
	else if (!ft_strcmp(str[0], "F") || !ft_strcmp(str[0], "C"))
		get_colour(&data, str);
	else
		print_error("missing or wrong identifier ❗");
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

void	get_colour(t_map **data, char **str)
{
	char	**colour;
	int		nbr;
	int		i;

	i = -1;
	colour = ft_split(str[1], ',');
	if (colour[0] && colour[1] && colour[2])
	{
		while (colour[++i])
		{
			nbr = ft_atoi(colour[i]);
			if (nbr > 255 || nbr < 0)
				print_error("wrong colour range❗");
			if (!ft_strcmp(str[0], "F"))
				(*data)->floor = ft_strjoin((*data)->floor, to_hex(nbr));
			else
				(*data)->ceiling = ft_strjoin((*data)->ceiling, to_hex(nbr));
		}
		if (!ft_strcmp(str[0], "F"))
				(*data)->floor = ft_strjoin((*data)->floor, "FF");
		else
				(*data)->ceiling = ft_strjoin((*data)->ceiling, "FF");
	}
	else
		print_error("wrong colour❗");
}
