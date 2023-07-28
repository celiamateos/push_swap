/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:28:26 by cmateos-          #+#    #+#             */
/*   Updated: 2023/07/11 18:10:57 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void    push_swap(t_stack **stack_a,  t_stack **stack_b)
{
    if (!stack_a || !stack_b)
        return;
    if (ft_stacksize(*stack_a) == 3)
        ft_sort_three(stack_a);
}

void    ft_sort_three(t_stack **stack)
{
    int     two;
    int     first;

    first = (*stack)->index;
    two = (*stack)->next->index;
    printf("\n FIRST:%d", first);
    printf("\n COND:%d", two);
    if (first == 2 && two == 1)
        ft_do_sa(stack);
    else if (first == 2 && two == 3)
        ft_do_rra(stack);
    else if (first == 3 && two == 1)
        ft_do_ra(stack);
    else if (first == 1 && two == 3)
    {
        ft_do_rra(stack);
        ft_do_sa(stack);
    }
    else
    {
        ft_do_sa(stack);
        ft_do_rra(stack);
    }
}