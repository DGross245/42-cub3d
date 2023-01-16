/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:01:20 by dgross            #+#    #+#             */
/*   Updated: 2023/01/16 15:43:54 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASH_H
# define TRASH_H

typedef struct s_trash_dump
{
	void				*garbage_pile;
	struct s_trash_dump	*next;
}t_dump;

typedef struct s_trash_bin
{
	void				*garbage;
	struct s_trash_bin	*next;
}t_bin;

//##########GLOABAL#########//

void	burn_it_down(t_dump *pile);
void	pile_up(t_dump	*pile);

//##########LOCAL##########//

void	empty_trash(t_bin *trash);
void	*collect_trash(t_bin *trash, int size, int quantity);

#endif