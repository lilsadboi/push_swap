/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:28:50 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/14 17:28:56 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_stack_size(t_stack *stack)
{
	t_stack	*temp;
	int		size;

	size = 0;
	if (stack)
	{
		size++;
		temp = stack;
		while (temp->next != stack)
		{
			temp = temp->next;
			size++;
		}
	}
	return (size);
}

int	ft_check_order(t_stack *stack)
{
	int	size;
	int	i;

	i = 1;
	size = ft_stack_size(stack);
	if (stack)
	{
		while (i < size)
		{
			if (stack->n > stack->next->n)
				return (0);
			stack = stack->next;
			i++;
		}
		return (1);
	}
	return (-1);
}

void	ft_print_stack(t_stack *stack)
{
	int	size;
	int	i;

	i = 0;
	size = ft_stack_size(stack);
	while (i < size)
	{
		ft_printf("%d\n", stack->n);
		stack = stack->next;
		i++;
	}
}

t_stack	*ft_smallest_stack(t_stack *stack)
{
	t_stack	*temp;
	int		size;
	int		j;

	temp = stack;
	size = ft_stack_size(stack);
	j = 0;
	if (stack)
	{
		while (j < size)
		{
			if (stack->n < temp->n)
				temp = stack;
			stack = stack->next;
			j++;
		}
	}
	return (temp);
}

int	ft_find_n_pos(t_stack *stack, int nb)
{
	int	size;
	int	i;

	i = 0;
	size = ft_stack_size(stack);
	while (i < size)
	{
		if (stack->n == nb)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}
