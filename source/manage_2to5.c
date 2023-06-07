/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_2to5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:50:58 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/16 14:51:01 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_manage_2(t_stack **a, t_stack **b)
{
	if ((*a)->n > (*a)->next->n)
		ft_dorot(a, b, 0);
}

void	ft_manage_3(t_stack **a, t_stack **b)
{
	if (!ft_check_order(*a))
	{
		if ((*a)->n > (*a)->prev->n && (*a)->n > (*a)->next->n)
		{
			if ((*a)->next->n > (*a)->prev->n)
			{
				ft_doswap(a, b, 0);
				ft_dorevrot(a, b, 0);
			}
			else if ((*a)->next->n < (*a)->prev->n)
				ft_dorot(a, b, 0);
		}
		else if ((*a)->n < (*a)->next->n && (*a)->next->n > (*a)->prev->n)
		{
			if ((*a)->n > (*a)->prev->n)
				ft_dorevrot(a, b, 0);
			else
			{
				ft_doswap(a, b, 0);
				ft_dorot(a, b, 0);
			}
		}
		else if ((*a)->n > (*a)->next->n)
			ft_doswap(a, b, 0);
	}
}

void	ft_manage_4to5(t_stack **a, t_stack **b)
{
	int		i;

	i = ft_stack_size(*a);
	if (!ft_check_order(*a))
	{
		while (i > 3)
		{
			if (ft_find_n_pos(*a, ft_smallest_stack(*a)->n) < ((i / 2 + 1)))
				while ((*a)->n != ft_smallest_stack(*a)->n)
					ft_dorot(a, b, 0);
			else
				while ((*a)->n != ft_smallest_stack(*a)->n)
					ft_dorevrot(a, b, 0);
			ft_dopush(a, b, 1);
			i--;
		}
		ft_manage_3(a, b);
		while (*b)
			ft_dopush(a, b, 0);
	}
}
