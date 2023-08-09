/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:30:08 by cmateos-          #+#    #+#             */
/*   Updated: 2023/07/11 18:12:34 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;
//STACK_UTILS:
t_stack	*ft_newnode(int nb);
void	ft_stackadd_back(t_stack **stack, t_stack *node);
void	ft_stackadd_front(t_stack **stack, t_stack *node);
t_stack	*ft_stacklast(t_stack *node);
int		ft_stacksize(t_stack *lst);
void	ft_stackclear(t_stack **stack);

//PUSH_SWAP PARSE
int		main(int argc, char **argv);
void	ft_start(t_stack **stack_a);
void	ft_fill_stack(char *arg, t_stack **stack_a);
void	ft_is_str(char *str, t_stack **stack_a);
void	ft_is_num(char *str, t_stack **stack_a);
void	ft_check_arg(t_stack **stack_a);
int		ft_atoi_pushswap(const char *str, t_stack **stack_a);
void	ft_check_char(char c, t_stack **stack_a);
int		ft_repeated_number(t_stack *stack_a);
int		ft_numbers_is_sorted(t_stack *stack_a);
void	ft_print_stack(t_stack *stack_a, t_stack *stack_b);
void	ft_index(t_stack **stack_a, int stack_size);

//PUSH_SWAP MOVES
void	ft_push_ab(t_stack **stack_from, t_stack **stack_dest);
void	ft_do_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_do_pb(t_stack **stack_b, t_stack **stack_a);
void	ft_swap_ab(t_stack *stack);
void	ft_do_sa(t_stack **stack_a);
void	ft_do_sb(t_stack **stack_b);
void	ft_do_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_do_ra(t_stack **stack_a);
void	ft_do_rb(t_stack **stack_b);
void	ft_do_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack);
void	ft_do_rra(t_stack **stack_a);
void	ft_do_rrb(t_stack **stack_b);
void	ft_do_rrr(t_stack **stack_a, t_stack **stack_b);

//PUSH_SWAP SORT
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **a, t_stack **b);
int		ft_is_sort(t_stack **stack);
int		ft_min_index(t_stack *min);
void	ft_radix_sort(t_stack **a, t_stack **b);
int		ft_max_bits(t_stack **a);

//SALIDAS DE ERRORES
void	ft_error1(t_stack **stack_a, int n);
#endif