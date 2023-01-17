/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:45:40 by dgross            #+#    #+#             */
/*   Updated: 2023/01/17 16:10:44 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h> // open
#include <stdlib.h> // malloc

int	parser(t_cub3d *cube, int argc, char **argv)
{
	int	fd;

	fd = -1;
	if (argc < 2)
	{
		print_error("map in missing ❗");
		return (ERROR);
	}
	if (argc > 2)
	{
		print_error("too many arguments❗");
		return (ERROR);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
	{
		print_error("no such file or directory ❗");
		return (ERROR);
	}
	reader(cube, fd);
	return (0);
}

void	reader(t_cub3d	*cube, int fd)
{
	char	*line;

	line = get_next_line(fd);
	(void)cube;
}
