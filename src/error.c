/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:53:11 by dgross            #+#    #+#             */
/*   Updated: 2023/02/01 10:02:50 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

#include <unistd.h> // write
#include <stdlib.h> // exit

void	print_error(char *reason)
{
	write(2, "❌ ERROR: ", 11);
	write(2, reason, ft_strlen(reason));
	write(2, "\n", 1);
	exit(1);
}
