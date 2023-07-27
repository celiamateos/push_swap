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
//ESTO ES UNA MIERDA
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

void    ft_swap_ab(t_stack **stack)
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
    

    
}