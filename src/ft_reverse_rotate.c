/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:36:06 by cmateos-          #+#    #+#             */
/*   Updated: 2023/07/28 12:36:07 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*beforelast;
	t_stack	*last;

	beforelast = *stack;
	while ((beforelast->next != NULL) && (beforelast->next->next != NULL))
		beforelast = beforelast->next;
	last = ft_stacklast(*stack);
	last->next = *stack;
	*stack = last;
	beforelast->next = NULL;
}

void	ft_do_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_do_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ft_do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
