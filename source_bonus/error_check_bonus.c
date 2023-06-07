/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:08:08 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/15 14:08:10 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_error_int_limit(char *nbr)
{
	long long	result;
	int			i;
	int			sign;
	int			dig;

	i = 0;
	sign = 1;
	result = 0;
	dig = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-')
		sign = -1;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9' && dig < 11)
	{
		result *= 10;
		result += nbr[i] - '0';
		i++;
		dig++;
	}
	if (dig > 10 || result * sign > INT_MAX || result * sign < INT_MIN)
		return (1);
	return (0);
}

int	ft_error_type(char *nbr)
{
	int	i;
	int	error;

	error = 0;
	if (nbr[0] == '+' || nbr[0] == '-' || ft_isdigit(nbr[0]))
	{
		if (nbr[1] == '\0' && (nbr[0] == '+' || nbr[0] == '-'))
			return (1);
		i = 1;
		while (nbr[i] && !error)
		{
			if (!ft_isdigit(nbr[i]))
				error = 1;
			i++;
		}
	}
	else
		error = 1;
	return (error);
}

int	ft_error_deal(int ac, char **av)
{
	int	error;
	int	x;
	int	y;

	error = 0;
	x = 0;
	while (x < ac && !error)
	{
		y = x + 1;
		while (y < ac && !error)
		{
			if (ft_atoi(av[x]) == ft_atoi(av[y]))
				error++;
			y++;
		}
		error += ft_error_type(av[x]);
		error += ft_error_int_limit(av[x]);
		x++;
	}
	return (error);
}
