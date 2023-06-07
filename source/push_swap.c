/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:43:47 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/14 17:43:50 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_mat(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	ft_not_one_av(char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = ft_matlen(av);
	if (ft_error_deal(i, av))
		write(2, "Error\n", 6);
	else
	{
		a = ft_fill_stack(av);
		b = NULL;
		if (i == 2)
			ft_manage_2(&a, &b);
		else if (i == 3)
			ft_manage_3(&a, &b);
		else if (i > 3 && i < 6)
			ft_manage_4to5(&a, &b);
		else
		{
			ft_manage_plus(&a, &b);
			ft_push_swap(&a, &b);
			ft_move_stack_up(&a, &b);
		}
		ft_free_stack(a);
	}
}

int	main(int ac, char **av)
{
	char	**mat;

	mat = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		mat = ft_split(av[1], ' ');
		if (mat)
		{
			ft_not_one_av(mat);
			ft_free_mat(mat);
		}
	}
	else
		ft_not_one_av(av + 1);
}
