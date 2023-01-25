/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:06:55 by dgross            #+#    #+#             */
/*   Updated: 2023/01/25 23:06:36 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

#include <fcntl.h> // open
#include <stddef.h> // NULL

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
		get_colour(&data, str);
	else
		print_error("missing or wrong identifier ❗");
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
