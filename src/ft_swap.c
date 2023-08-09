/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:35:45 by cmateos-          #+#    #+#             */
/*   Updated: 2023/07/28 12:35:47 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ft_swap_ab(t_stack *stack)
{
	long int	nb;
	int			index;

	if (ft_stacksize(stack) < 2)
		return ;
	nb = stack->value;
	stack->value = stack->next->value;
	stack->next->value = nb;
	index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = index;
}

void	ft_do_sa(t_stack **stack_a)
{
	ft_swap_ab(*stack_a);
	ft_printf("sa\n");
}

void	ft_do_sb(t_stack **stack_b)
{
	ft_swap_ab(*stack_b);
	ft_printf("sb\n");
}

void	ft_do_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_ab(*stack_a);
	ft_swap_ab(*stack_b);
	ft_printf("ss\n");
}
