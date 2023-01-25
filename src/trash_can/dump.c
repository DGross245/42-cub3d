/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:12:22 by dgross            #+#    #+#             */
/*   Updated: 2023/01/25 22:42:41 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"
#include "libft.h"

#include <stdlib.h> // free

void	*create_pile(t_dump *dump, int size, int quantity)
{
	void	*pile;

	pile = ft_calloc(quantity, size);
	if (pile == NULL)
		return (NULL);
	pile_up(&dump, new_container(pile));
	return (pile);
}

t_dump	*new_container(void *pile)
{
	t_dump	*container;

	container = malloc(sizeof(t_dump));
	if (container == NULL)
		return (NULL);
	container->garbage_pile = pile;
	container->free_func = &free;
	container->next = NULL;
	return (container);
}

void	pile_up(t_dump **dump, t_dump *pile)
{
	pile->next = *dump;
	*dump = pile;
}

void	burn_it_down(t_dump *dump)
{
	t_dump	*tmp;

	while (dump != NULL)
	{
		tmp = dump;
		dump = dump->next;
		tmp->free_func(tmp->garbage_pile);
		free(tmp);
	}
}

void	free_double(void **double_pointer)
{
	int	i;

	i = -1;
	while (double_pointer[++i] != NULL)
		free(double_pointer[i]);
	free(double_pointer[i]);
	free(double_pointer);
}
