/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:46:24 by dgross            #+#    #+#             */
/*   Updated: 2023/02/23 12:46:38 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	check_char(char const s, char *chars)
{
	int	i;

	i = 0;
	while (chars[i])
	{
		if (s == chars[i])
			return (1);
		i++;
	}
	return (0);
}

unsigned int	ft_word_count(char const *s, char *chars)
{
	unsigned int	counter;
	unsigned int	i;
	unsigned int	j;

	counter = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!check_char(s[i], chars) && j == 0)
		{
			counter++;
			j = 1;
		}
		else if (check_char(s[i], chars))
			j = 0;
		i++;
	}
	return (counter);
}

unsigned int	ft_letter_count(const char *s, char *chars, unsigned int i)
{
	unsigned int	k;

	k = 0;
	while (s[i] != '\0' && !check_char(s[i], chars))
	{
		i++;
		k++;
	}
	return (k);
}

char	**ft_split_2(char const *s, char *chars)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		l;
	unsigned int		wrd_amt;
	char				**strb;

	i = 0;
	j = 0;
	if (!s || !chars)
		return (NULL);
	wrd_amt = ft_word_count(s, chars) + 1;
	strb = (char **)malloc(sizeof(char *) * wrd_amt);
	if (!strb)
		return (NULL);
	while (i < ft_strlen(s) && j < wrd_amt - 1)
	{
		while (check_char(s[i], chars))
			i++;
		l = ft_letter_count(s, chars, i);
		strb[j++] = ft_substr(s, i, l);
		i = i + l;
		s++;
	}
	strb[j] = NULL;
	return (strb);
}
