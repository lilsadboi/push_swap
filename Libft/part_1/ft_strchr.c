/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:59:04 by gmorelli          #+#    #+#             */
/*   Updated: 2022/10/10 15:32:50 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*p;
	int		x;

	x = 0;
	p = (char *) str;
	while (p[x] != '\0')
	{
		if (p[x] == c)
			return (&p[x]);
		else
			x++;
	}
	if (p[x] == c)
		return (&p[x]);
	return (0);
}
