/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:29:30 by dgross            #+#    #+#             */
/*   Updated: 2023/01/21 16:51:21 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

#include <fcntl.h> // open
#include <stdio.h>
////void	map_checker(char **map)
////{
	
////}

void	check_input(t_cub3d *cube)
{
	char	**check;
	int		i;
	int		j;

	i = 0;
	while (cube->input[i] != NULL)
	{
		j = 0;
		while (cube->input[i][j] != '\0' && !ft_isprint(cube->input[i][j]))
			j++;
		if (cube->input[i][j] != '\0' && !ft_isdigit(cube->input[i][j]))
		{
			printf("kek\n");
			check = ft_split(cube->input[i++], ' ');
			//get_path();
			//free_double();
			i++;
		}
		else if (ft_isdigit(cube->input[i][j]))
		{
			printf("kekw\n");/// map_checker();
			i++;
		}
	}
}

//void	get_path(t_map *data)
//{
//	if (!ft_strcmp(str[0], "NO"))
//		data->north = open(str[1], O_RDONLY);
//	else if (!ft_strcmp(str[0], "SO"))
//		data->south = open(str[1], O_RDONLY);
//	else if (!ft_strcmp(str[0], "WE"))
//		data->west = open(str[1], O_RDONLY);
//	else if (!ft_strcmp(str[0], "EA"))
//		data->east = open(str[1], O_RDONLY);
//}
