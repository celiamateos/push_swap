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
/*void    ft_swap_ab(t_stack **stack)
{
    t_stack *nodo3;
    t_stack *nodo1;

    if (!*stack || ft_stacksize(*stack) < 2)
        return ;

    nodo1 = *stack;
    nodo3 = (*stack)->next->next;
    (*stack)->next->next = *stack; //El segundo apunta al primero
    *stack = (*stack)->next; //El primero ahora va a ser el nodo2
    (*stack)->next = nodo1; //El primer nodo va a apuntar al nodo1
    nodo1->next = nodo3; //El nodo1 va a apuntar al nodo3
    //PUTA RAYADA. FUNCIONA SIN LEAKS
}*/

void    ft_swap_ab(t_stack *stack)
{
    long int nb;
    int index;

    if (ft_stacksize(stack) < 2)
        return ;
    nb = stack->value;
    stack->value = stack->next->value;
    stack->next->value = nb;
    
    index = stack->index;
    stack->index = stack->next->index;
    stack->next->index = index;
}

void    ft_do_sa(t_stack **stack_a)
{
    ft_swap_ab(*stack_a);
    ft_printf("sa\n");
}
void    ft_do_sb(t_stack **stack_b)
{
    ft_swap_ab(*stack_b);
    ft_printf("sb\n");
}
void    ft_do_ss(t_stack **stack_a, t_stack **stack_b)
{
    ft_swap_ab(*stack_a);
    ft_swap_ab(*stack_b);
    ft_printf("ss\n");
}
