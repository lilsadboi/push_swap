/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:58:44 by gmorelli          #+#    #+#             */
/*   Updated: 2023/04/12 12:58:47 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(t_stack *first, t_stack *moveman)
{
	int		x;
	int		count;
	int		countrev;
	t_stack	*temp;

	temp = moveman;
	count = 0;
	countrev = 0;
	x = first->n;
	while (x != temp->n)
	{
		temp = temp->next;
		count++;
	}
	temp = moveman;
	while (x != temp->n)
	{
		temp = temp->prev;
		countrev--;
	}
	if ((countrev * -1) < count)
		return (countrev);
	return (count);
}

int	ft_prev_and_next(t_stack *a, int n)
{
	int		i;
	int		size;
	int		x;
	t_stack	*temp;

	i = 0;
	size = ft_stack_size(a);
	x = ft_count(ft_smallest_stack(a), a);
	temp = a;
	while (i < size)
	{
		if (temp->n > n && temp->prev->n < n)
		{
			if (i > ((size / 2) + 1))
				x = i - size;
			else
				x = i;
		}
		temp = temp->next;
		i++;
	}
	return (x);
}

void	ft_move_stack_up(t_stack **a, t_stack **b)
{
	if (ft_pos_with_n(*a, ft_smallest_stack(*a)->n) > ft_stack_size(*a) / 2 + 1)
	{
		while (ft_pos_with_n(*a, ft_smallest_stack(*a)->n) != 1)
			ft_dorevrot(a, b, 0);
	}
	else
	{
		while (ft_pos_with_n(*a, ft_smallest_stack(*a)->n) != 1)
			ft_dorot(a, b, 0);
	}
}

void	ft_push_swap(t_stack **a, t_stack **b)
{
	int	i;
	int	x;

	i = 0;
	x = ft_stack_size(*b);
	while (i < x)
	{
		ft_array_sort_number(a, b);
		i++;
	}
}
