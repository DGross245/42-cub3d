/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:45:40 by dgross            #+#    #+#             */
/*   Updated: 2023/01/26 12:00:16 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h> // open
#include <stdlib.h> // malloc
#include <stdio.h>

void	parser(t_cub3d *cube, int argc, char **argv)
{
	int	fd;

	fd = -1;
	if (argc < 2)
		print_error("path to map in missing ❗");
	if (argc > 2)
		print_error("too many arguments❗");
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4) != 0)
		print_error("file doesnt end with .cub ❗");
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		print_error("no such file or directory ❗");
	reader(cube, fd);
	check_input(cube);
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

	size = 0;
	line = get_next_line(fd);
	if (!line)
		print_error("file is empty ❗");
	while (line != NULL)
	{
		cube->input = ft_realloc(cube->input, sizeof(char *) * (size + 2));
		cube->input[size++] = remove_line(line);
		line = get_next_line(fd);
	}
	cube->input[size] = NULL;
}
