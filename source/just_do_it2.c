/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_do_it2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:14:58 by gmorelli          #+#    #+#             */
/*   Updated: 2023/04/13 16:15:01 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dualrot(t_stack **a, t_stack **b, int *arr_a, int *arr_b)
{
	while ((*arr_a) > 0 && (*arr_b) > 0)
	{
		ft_dorot(a, b, 2);
		(*arr_a)--;
		(*arr_b)--;
	}
}

void	ft_dualrevrot(t_stack **a, t_stack **b, int *arr_a, int *arr_b)
{
	while ((*arr_a) < 0 && (*arr_b) < 0)
	{
		ft_dorevrot(a, b, 2);
		(*arr_a)++;
		(*arr_b)++;
	}
}

void	ft_do_a(t_stack **a, t_stack **b, int *arr_a)
{
	if (*arr_a > 0)
	{
		while (*arr_a > 0)
		{
			ft_dorot(a, b, 0);
			(*arr_a)--;
		}
	}
	else if (*arr_a < 0)
	{
		while (*arr_a < 0)
		{
			ft_dorevrot(a, b, 0);
			(*arr_a)++;
		}
	}
}

void	ft_do_b(t_stack **a, t_stack **b, int *arr_b)
{
	if (*arr_b > 0)
	{
		while (*arr_b > 0)
		{
			ft_dorot(a, b, 1);
			(*arr_b)--;
		}
	}
	else if (*arr_b < 0)
	{
		while (*arr_b < 0)
		{
			ft_dorevrot(a, b, 1);
			(*arr_b)++;
		}
	}
}

void	ft_execute_move(t_stack **a, t_stack **b, int arr_a, int arr_b)
{
	ft_dualrot(a, b, &arr_a, &arr_b);
	ft_dualrevrot(a, b, &arr_a, &arr_b);
	ft_do_a(a, b, &arr_a);
	ft_do_b(a, b, &arr_b);
	ft_dopush(a, b, 0);
}
