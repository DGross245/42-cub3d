/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:20:32 by dgross            #+#    #+#             */
/*   Updated: 2024/05/17 23:33:17 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrcnt(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}
