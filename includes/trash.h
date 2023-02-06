/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:01:20 by dgross            #+#    #+#             */
/*   Updated: 2023/02/06 13:22:35 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASH_H
# define TRASH_H

typedef struct s_trash_dump
{
	void				*garbage_pile;
	void				(*free_func)(void	*trash);
	struct s_trash_dump	*next;
}t_dump;

typedef struct s_trash_bin
{
	void				*garbage;
	void				(*free_func)(void	*trash);
	struct s_trash_bin	*next;
}t_bin;

typedef struct s_gc
{
	t_dump	*dump;
	t_bin	*bin;
}t_gc;

//##########GLOABAL#########//

void	burn_it_down(t_dump *pile);
void	*create_pile(t_dump *dump, int size, int quantity);
void	pile_up(t_dump **dump, t_dump *pile);
t_dump	*new_container(void *pile);

//###########LOCAL###########//

void	empty_trash(t_bin *trash);
void	*collect_trash(t_bin *trash, int size, int quantity);

//#########################//

t_bin	*new_garbage_bag(void *trash);
void	free_double(void **double_pointer);
void	throw_garbage_on_top(t_bin **garbage_pile, t_bin *garbage);

#endif