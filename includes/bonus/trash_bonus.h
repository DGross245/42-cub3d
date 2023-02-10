/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:10:56 by dgross            #+#    #+#             */
/*   Updated: 2023/02/10 13:14:19 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASH_BONUS_H
# define TRASH_BONUS_H

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
	int		bin_status;
	int		dump_status;
}t_gc;

//##########GLOABAL#########//

void	burn_it_down(t_gc *gc, t_dump *pile);
void	*create_pile(t_gc *gc, int size, int quantity);
void	pile_up(t_dump **dump, t_dump *pile);
t_dump	*new_container(t_gc *gc, void *pile);

//###########LOCAL###########//

void	empty_trash(t_gc *gc, t_bin *trash);
void	*collect_trash(t_gc *gc, int size, int quantity);

//#########################//

t_bin	*new_garbage_bag(t_gc *gc, void *trash);
void	free_double(void **double_pointer);
void	throw_garbage_on_top(t_bin **garbage_pile, t_bin *garbage);

#endif