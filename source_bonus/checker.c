/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:44:39 by gmorelli          #+#    #+#             */
/*   Updated: 2023/04/27 16:44:41 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	ft_ok_or_ko(t_stack *a, t_stack *b)
{
	if (ft_check_order(a) != 1 || ft_stack_size(b) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	ft_not_one_av(char **av)
{
	int			i;
	char		*comm;
	t_stack		*a;
	t_stack		*b;

	i = ft_matlen(av);
	if (ft_error_deal(i, av))
		write(2, "Error\n", 6);
	else
	{
		i = 0;
		a = ft_fill_stack(av);
		b = NULL;
		comm = av[0];
		while (i == 0 && comm)
		{
			comm = get_next_line(0);
			i = ft_comm_checker(comm, &a, &b);
			free(comm);
		}
		ft_ok_or_ko(a, b);
		ft_free_stack(a);
		if (b)
			ft_free_stack(b);
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
	get_next_line(-42);
}
