/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:00:24 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/08 16:00:27 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	int	temp;

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/*    t_stack *stack_plus;

    if (*stack && (*stack) != (*stack->next))
    {
        if ((*stack)->next == (*stack)->prev)
            (*stack) = (*stack)->next;
        else
            stack_plus = (*stack)->prev;
            (*stack)->prev = (*stack)->next;
            (*stack)->next = (*stack)->next->next;
            (*stack)->next->prev = (*stack);
            stack_plus->next = (*stack)->prev;
            stack_plus->prev->next = stack_plus;
            stack_plus->next->next = (*stack);
            (*stack) = stack_plus->next;
    }*/
