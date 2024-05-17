/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:00:16 by dgross            #+#    #+#             */
/*   Updated: 2024/05/17 23:34:50 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

#include <stddef.h> // size_t NULL
#include <stdlib.h> // malloc free

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	is_valid(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0' || c == '1')
		return (1);
	else
		return (0);
}

void	is_player_set(t_cub3d *cube)
{
	if (cube->player.facing == '\0')
		print_error(cube, "missing player's spawn & orientation ❗");
}

char	*gc_strdup(t_cub3d *cube, const char *s1)
{	
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + 1;
	str = malloc (sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len);
	pile_up(&cube->gc.dump, new_container(&cube->gc, str));
	return (str);
}

unsigned long	rgba_to_uint(int r, int g, int b, int a)
{
	return (((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) \
			+ (a & 0xff));
}
