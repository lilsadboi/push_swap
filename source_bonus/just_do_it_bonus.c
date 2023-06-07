/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_do_it_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:48:15 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/16 14:48:18 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_doswap(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
		ft_swap(a);
	else if (type == 1)
		ft_swap(b);
	else if (type == 2)
	{
		ft_swap(a);
		ft_swap(b);
	}
}

void	ft_dopush(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
		ft_push(a, b);
	else if (type == 1)
		ft_push(b, a);
}

void	ft_dorot(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
		ft_rotate(a);
	else if (type == 1)
		ft_rotate(b);
	else if (type == 2)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
}

void	ft_dorevrot(t_stack **a, t_stack **b, int type)
{
	if (type == 0)
		ft_rev_rotate(a);
	else if (type == 1)
		ft_rev_rotate(b);
	else if (type == 2)
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
	}
}
