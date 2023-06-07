/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:12:14 by gmorelli          #+#    #+#             */
/*   Updated: 2023/04/28 16:12:20 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_comm_checker2(char *comm, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (comm)
	{
		if (!ft_strcmp(comm, "sa\n"))
			ft_doswap(a, b, 0);
		else if (!ft_strcmp(comm, "sb\n"))
			ft_doswap(a, b, 1);
		else if (!ft_strcmp(comm, "ss\n"))
			ft_doswap(a, b, 2);
		else if (!ft_strcmp(comm, "pa\n"))
			ft_dopush(a, b, 0);
		else if (!ft_strcmp(comm, "pb\n"))
			ft_dopush(a, b, 1);
		else
			i = ft_error();
	}
	return (i);
}

int	ft_comm_checker(char *comm, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (comm)
	{
		if (!ft_strcmp(comm, "ra\n"))
			ft_dorot(a, b, 0);
		else if (!ft_strcmp(comm, "rb\n"))
			ft_dorot(a, b, 1);
		else if (!ft_strcmp(comm, "rr\n"))
			ft_dorot(a, b, 2);
		else if (!ft_strcmp(comm, "rra\n"))
			ft_dorevrot(a, b, 0);
		else if (!ft_strcmp(comm, "rrb\n"))
			ft_dorevrot(a, b, 1);
		else if (!ft_strcmp(comm, "rrr\n"))
			ft_dorevrot(a, b, 2);
		else
			i = ft_comm_checker2(comm, a, b);
	}
	return (i);
}
