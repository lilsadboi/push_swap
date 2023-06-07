/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:37:05 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/08 15:37:07 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rotate(t_stack **stack)
{
	if (*stack)
		(*stack) = (*stack)->next;
}

void	ft_rev_rotate(t_stack **stack)
{
	if (*stack)
		(*stack) = (*stack)->prev;
}
