/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:28:09 by gmorelli          #+#    #+#             */
/*   Updated: 2023/04/28 15:28:13 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../Libft/libft.h"

typedef struct s_stack
{
	int					n;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

t_stack	*ft_fill_stack(char **av);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **dest, t_stack **src);
int		ft_stack_size(t_stack *stack);
int		ft_check_order(t_stack *stack);
void	ft_print_stack(t_stack *stack);
t_stack	*ft_smallest_stack(t_stack *stack);
int		ft_error_deal(int ac, char **av);
void	ft_manage_2(t_stack **a, t_stack **b);
void	ft_manage_3(t_stack **a, t_stack **b);
void	ft_manage_4to5(t_stack **a, t_stack **b);
void	ft_doswap(t_stack **a, t_stack **b, int type);
void	ft_dopush(t_stack **a, t_stack **b, int type);
void	ft_dorot(t_stack **a, t_stack **b, int type);
void	ft_dorevrot(t_stack **a, t_stack **b, int type);
void	ft_manage_plus(t_stack **a, t_stack **b);
int		ft_max_i(int *lis_len, int size);
void	ft_valueset(int **lis_pos, int value, int size);
int		ft_n_at_pos(t_stack *stack, int lis_pos);
int		ft_find_int(int *arg, int value, int size);
int		ft_pos_with_n(t_stack *stack, int n);
void	ft_array_sort_number(t_stack **a, t_stack **b);
void	ft_execute_move(t_stack **a, t_stack **b, int arr_a, int arr_b);
int		ft_prev_and_next(t_stack *a, int n);
int		ft_find_n_pos(t_stack *stack, int nb);
void	ft_push_swap(t_stack **a, t_stack **b);
void	ft_move_stack_up(t_stack **a, t_stack **b, int nb);
void	ft_free_stack(t_stack *stack);
int		ft_comm_checker(char *comm, t_stack **a, t_stack **b);
int		ft_error(void);

#endif
