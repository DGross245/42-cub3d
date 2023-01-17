/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:45:40 by dgross            #+#    #+#             */
/*   Updated: 2023/01/17 07:09:21 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <fcntl.h> // open

int	parser(int argc, char *argv)
{
	int	fd;

	if (argc < 2)
	{
		print_error("Map in missing ❗");
		return (ERROR);
	}
	if (argc > 2)
	{
		print_error("too many arguments❗");
		return (ERROR);
	}
	fd = open(argv[1]);
}
