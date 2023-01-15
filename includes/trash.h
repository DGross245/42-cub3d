/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:01:20 by dgross            #+#    #+#             */
/*   Updated: 2023/01/15 12:08:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASH_H
# define TRASH_H

typedef struct s_trash
{
	void			*content;
	struct s_trash	*next;
}t_trash;

void	empty_trash(t_trash *trash);

#endif