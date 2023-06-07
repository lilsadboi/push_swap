/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wherever.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:15:57 by gmorelli          #+#    #+#             */
/*   Updated: 2023/04/05 16:16:00 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_array_a(t_stack *a, t_stack *b)
{
	int	size;
	int	*arr_a;
	int	b_value;
	int	i;

	size = ft_stack_size(b);
	arr_a = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		b_value = b->n;
		arr_a[i] = ft_prev_and_next(a, b_value);
		ft_rotate(&b);
		i++;
	}
	return (arr_a);
}

int	*ft_array_b(t_stack *b)
{
	int	size;
	int	*arr_b;
	int	i;

	size = ft_stack_size(b);
	arr_b = malloc(sizeof(int) * size);
	i = 0;
	if (i < size)
	{
		i = 0;
		while (i < (size / 2))
		{
			arr_b[size - i - 1] = (i + 1) * -1;
			i++;
		}
		i = 0;
		while (i < (size / 2) + 1)
		{
			arr_b[i] = i;
			i++;
		}
	}
	return (arr_b);
}

int	ft_minmax(int a, int b)
{
	int	n;

	if (a >= 0 && b >= 0)
	{
		if (a >= b)
			n = a;
		else
			n = b;
	}
	if (a < 0 && b < 0)
	{
		if (a <= b)
			n = a;
		else
			n = b;
	}
	return (n);
}

int	ft_moveset_value(int a, int b)
{
	int	move;

	move = 0;
	if (a >= 0 && b >= 0)
		move = ft_minmax(a, b);
	else if (a < 0 && b < 0)
		move = (ft_minmax(a, b)) * -1;
	else if (a >= 0 && b < 0)
		move = a + (b * -1);
	else if (a < 0 && b >= 0)
		move = (a * -1) + b;
	return (move);
}

void	ft_array_sort_number(t_stack **a, t_stack **b)
{
	int	*arr_a;
	int	*arr_b;
	int	i;
	int	x;
	int	pos;

	arr_a = ft_array_a(*a, *b);
	arr_b = ft_array_b(*b);
	i = 0;
	x = ft_moveset_value(arr_a[i], arr_b[i]);
	pos = 0;
	while (i < ft_stack_size(*b))
	{
		if (ft_moveset_value(arr_a[i], arr_b[i]) < x)
		{
			x = ft_moveset_value(arr_a[i], arr_b[i]);
			pos = i;
		}
		i++;
	}
	ft_execute_move(a, b, arr_a[pos], arr_b[pos]);
	free(arr_a);
	free(arr_b);
}
