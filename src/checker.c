/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:29:30 by dgross            #+#    #+#             */
/*   Updated: 2023/01/24 18:45:28 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "trash.h"

#include <fcntl.h> // open
#include <stdlib.h> // malloc
#include <stdio.h>
#include <unistd.h>

void	check_map(t_map *data)
{
	int	i;
	int	j;
	int	max;

	j = 0;
	i = -1;
	max = ft_ptrcnt(data->map);
	while (data->map[++i] && data->map[i][j])
	{
		while (data->map[i][j] && ft_isspace(data->map[i][j]))
			j++;
		if (data->map[i][j] && i == 0)
		{
			while (data->map[i][j] && data->map[i][j] == '1')
				j++;
			if (data->map[i][j])
				print_error("invalid map ❗");
		}
		else if (data->map[i][j] && i == max)
		{
			while (data->map[i][j] && data->map[i][j] == '1')
				j++;
			if (data->map[i][j])
				print_error("invalid map ❗");
		}
		else if (data->map[i][j] != '1'
			|| data->map[i][ft_strlen(data->map[i])] != '1')
			print_error("invalid map ❗");
		j = 0;
	}
}

void	get_map(t_map *data, t_cub3d *cube, int *i)
{
	int	j;
	int	len;
	int	idx;

	idx = *i;
	len = 0;
	j = 0;
	while (cube->input[idx++] != NULL)
		len++;
	data->map = ft_calloc(len + 1, sizeof(char *));
	while (cube->input[(*i)])
		data->map[j++] = ft_strdup(cube->input[(*i)++]);
	data->map[j] = NULL;
	(*i)--;
	check_map(data);
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
		else if (cube->input[i][j] != '\0' && ft_isdigit(cube->input[i][j]))
			get_map(&cube->data, cube, &i);
		i++;
	}
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
