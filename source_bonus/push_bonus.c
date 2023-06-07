/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:54:44 by gmorelli          #+#    #+#             */
/*   Updated: 2023/03/09 17:54:46 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_self_link(t_stack **stack)
{
	(*stack)->next = *stack;
	(*stack)->prev = *stack;
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (*src)
	{
		temp = *src;
		if (ft_stack_size(*src) >= 2)
		{
			(*src)->next->prev = (*src)->prev;
			(*src)->prev->next = (*src)->next;
			*src = (*src)->next;
		}
		else
			*src = NULL;
		if (*dest)
		{
			temp->next = (*dest);
			temp->prev = (*dest)->prev;
			(*dest)->prev->next = temp;
			(*dest)->prev = temp;
		}
		else
			ft_self_link(&temp);
		*dest = temp;
	}
}
