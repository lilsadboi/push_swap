/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:36:28 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/08 15:36:31 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*temp;
	int		i;
	int		size;

	size = ft_stack_size(stack);
	if (size > 0)
	{
		temp = stack->next;
		i = 0;
		while (i < size)
		{
			free(stack);
			stack = temp;
			i++;
			if (i < size)
				temp = temp->next;
		}
	}
}

t_stack	*ft_new_node(t_stack *prev, int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->n = n;
	node->prev = prev;
	node->next = NULL;
	return (node);
}

t_stack	*ft_fill_stack(char **av)
{
	t_stack	*stack;
	t_stack	*temp;
	int		i;
	int		ac;

	stack = ft_new_node(NULL, ft_atoi(av[0]));
	temp = stack;
	i = 1;
	ac = ft_matlen(av);
	while (i < ac)
	{
		temp->next = ft_new_node(temp, ft_atoi(av[i]));
		temp = temp->next;
		i++;
	}
	temp->next = stack;
	stack->prev = temp;
	return (stack);
}
