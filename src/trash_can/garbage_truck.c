/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_truck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:37:18 by dgross            #+#    #+#             */
/*   Updated: 2023/01/16 14:12:03 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"
#include "libft.h"

void	*collect_trash(int size, int quantity)
{
	void	*trash;

	trash = ft_calloc(quantity, size);
	
	return (trash);
}

void	throw_garbage_on_top(t_trash **garbage_pile, t_trash *garbige)
{
	garbige->next = *garbage_pile;
	*garbage_pile = garbige;
}
