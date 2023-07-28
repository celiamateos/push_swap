/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:50:44 by cmateos           #+#    #+#             */
/*   Updated: 2023/07/17 19:50:46 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void    ft_push_ab(t_stack **stack_from, t_stack **stack_dest)
{
    t_stack *temp;

    if (!stack_from)
        return ;

    temp = (*stack_from)->next;
    (*stack_from)->next = *stack_dest;
    *stack_dest = *stack_from;
    *stack_from = temp;
    
}

void    ft_do_pa(t_stack **stack_a, t_stack **stack_b)
{
    ft_push_ab(stack_a, stack_b);
    ft_printf("pa\n");
}

void    ft_do_pb(t_stack **stack_b, t_stack **stack_a)
{
    ft_push_ab(stack_b, stack_a);
    ft_printf("pb\n");
}
