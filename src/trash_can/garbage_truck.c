/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_truck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:37:18 by dgross            #+#    #+#             */
/*   Updated: 2023/01/17 16:27:23 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"
#include "libft.h"

#include <stdlib.h> // free

void	*collect_trash(t_bin *bin, int size, int quantity)
{
	void	*trash;

	trash = ft_calloc(quantity, size);
	if (trash == NULL)
		return (NULL);
	throw_garbage_on_top(&bin, new_garbage_bag(trash));
	return (trash);
}

t_bin	*new_garbage_bag(void *trash)
{
	t_bin	*garbage_bag;

	garbage_bag = malloc(sizeof(t_bin));
	if (garbage_bag == NULL)
		return (NULL);
	garbage_bag->garbage = trash;
	garbage_bag->free_func = &free; // art von free noch
	garbage_bag->next = NULL;
	return (garbage_bag);
}

void	throw_garbage_on_top(t_bin **garbage_pile, t_bin *garbage)
{
	garbage->next = *garbage_pile;
	*garbage_pile = garbage;
}

void	empty_trash(t_bin	*bin)
{
	t_bin	*tmp;

	while (bin != NULL)
	{
		tmp = bin;
		bin = bin->next;
		tmp->free_func(tmp->garbage);
		free(tmp);
	}
}
