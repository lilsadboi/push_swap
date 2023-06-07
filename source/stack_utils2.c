/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:46:55 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/30 11:46:59 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_valueset(int **lis_pos, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*lis_pos)[i] = value;
		i++;
	}
}

int	ft_n_at_pos(t_stack *stack, int lis_pos)
{
	while (--lis_pos > 0 && stack)
		stack = stack->next;
	if (stack)
		return (stack->n);
	return (0);
}

int	ft_pos_with_n(t_stack *stack, int n)
{
	int	pos;
	int	size;

	pos = 0;
	while (stack)
	{
		pos++;
		size = ft_stack_size(stack);
		while (stack->n != n && pos < size)
		{
			pos++;
			stack = stack->next;
		}
		if (stack->n == n)
			return (pos);
	}
	return (0);
}

int	ft_max_i(int *lis_len, int size)
{
	int	i;
	int	value;
	int	max_i;

	i = 0;
	value = lis_len[0];
	max_i = 0;
	while (i < size)
	{
		if (lis_len[i] > value)
		{
			value = lis_len[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}

int	ft_find_int(int *arg, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arg[i] == value)
			return (1);
		i++;
	}
	return (0);
}
