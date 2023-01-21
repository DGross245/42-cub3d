/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:45:40 by dgross            #+#    #+#             */
/*   Updated: 2023/01/21 10:27:37 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h> // open
#include <stdlib.h> // malloc
#include <stdio.h>
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

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (ptr != NULL)
	{
		ft_memcpy(new_ptr, ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
}

char	*remove_line(char *line)
{
	char	*new_line;

	if (line[ft_strlen(line) - 1] != '\n')
	{
		new_line = ft_strdup(line);
		free(line);
		line = NULL;
		return (new_line);
	}
	new_line = ft_calloc((ft_strlen(line) + 1), sizeof(char));
	ft_strlcpy(new_line, line, ft_strlen(line));
	new_line[ft_strlen(line)] = '\0';
	free(line);
	line = NULL;
	return (new_line);
}

void	reader(t_cub3d	*cube, int fd)
{
	char	*line;
	int		size;

	cube->data = NULL;
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		cube->data = ft_realloc(cube->data, sizeof(char *) + (size + 1));
		cube->data[size] = remove_line(line);
		printf("%s\n", cube->data[size]);
		size++;
		line = get_next_line(fd);
	}
	if (cube->data[1] != NULL)
		printf("%s\n", cube->data[1]);
}
