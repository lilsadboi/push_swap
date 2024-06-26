/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:40:31 by gmorelli          #+#    #+#             */
/*   Updated: 2022/10/14 10:43:43 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	if (s1 != 0 && set != 0)
	{
		while (s1[i] && ft_strchr(set, s1[i]) != 0)
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) != 0 && j > i)
			j--;
		p = malloc(sizeof(char) * (j - i + 1));
		if (p)
			ft_strlcpy(p, &s1[i], j - i + 1);
	}
	else
	{
		p = malloc(sizeof(char));
		p = 0;
	}
	return (p);
}
