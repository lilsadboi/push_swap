/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:55:07 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/27 10:55:09 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_pre_pos(int *lis_pos, int max_i, int size)
{
	int	i;
	int	temp;
	int	*pre_pos;

	i = 0;
	temp = max_i;
	pre_pos = malloc(sizeof(int) * size);
	while (i < size)
	{
		pre_pos[i] = temp;
		temp = lis_pos[temp];
		i++;
	}
	free(lis_pos);
	return (pre_pos);
}

void	ft_lis(t_stack *stack, int **lis_len, int **lis_pos)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = ft_stack_size(stack);
	ft_valueset(lis_pos, -1, size);
	(*lis_len)[0] = 1;
	while (i < size)
	{
		(*lis_len)[i] = 1;
		j = 0;
		while (j < i)
		{
			if (ft_n_at_pos(stack, i + 1) > ft_n_at_pos(stack, j + 1) \
				&& (*lis_len)[i] <= (*lis_len)[j] + 1)
			{
				(*lis_len)[i] = (*lis_len)[j] + 1;
				(*lis_pos)[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_push_not_lis(t_stack **a, t_stack **b, int *lis, int lis_size)
{
	int		size;
	t_stack	*temp;

	size = ft_stack_size(*a);
	while (size - lis_size > 0)
	{
		temp = *a;
		while (ft_find_int(lis, temp->n, lis_size))
			temp = temp->next;
		if (ft_pos_with_n(*a, temp->n) > size / 2)
		{
			while (ft_pos_with_n(*a, temp->n) != 1)
				ft_dorevrot(a, b, 0);
		}
		else
		{
			while (ft_pos_with_n(*a, temp->n) != 1)
				ft_dorot(a, b, 0);
		}
		ft_dopush(a, b, 1);
		size--;
	}
}

int	*ft_real_lis(t_stack *stack, int *lis_pos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis_pos[i] = ft_n_at_pos(stack, lis_pos[i] + 1);
		i++;
	}
	return (lis_pos);
}

void	ft_manage_plus(t_stack **a, t_stack **b)
{
	int	size;
	int	*lis_len;
	int	*lis_pos;
	int	max_i;

	size = ft_stack_size(*a);
	lis_len = malloc(sizeof(int) * (size));
	lis_pos = malloc(sizeof(int) * (size));
	ft_lis(*a, &lis_len, &lis_pos);
	max_i = ft_max_i(lis_pos, size);
	lis_pos = ft_pre_pos(lis_pos, max_i, lis_len[max_i]);
	lis_pos = ft_real_lis(*a, lis_pos, lis_len[max_i]);
	ft_push_not_lis(a, b, lis_pos, lis_len[max_i]);
	free (lis_len);
	free (lis_pos);
}
