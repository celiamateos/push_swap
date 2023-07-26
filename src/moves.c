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
    t_stack *aux;
    
    if (!stack_from)
        return ;
    temp = ft_newnode(0);
    temp->value = (*stack_from)->value;
    temp->index = (*stack_from)->index;
    ft_stackadd_front(stack_dest, temp);
    aux = (*stack_from)->next;
    free(*stack_from);
    *stack_from = aux;
    //CREO QUE FUNCIONA OK SIN LEAKS
}

void    ft_swap_ab(t_stack **stack)
{
    t_stack *temp;
    t_stack *aux;

    if (!*stack || ft_stacksize(*stack) < 3)
        return ;
    aux = (*stack);

    temp = ft_newnode(0);
    temp->value = (*stack)->value;
    temp->index = (*stack)->index;
    free (*stack);
    (*stack) = (*stack)->next;
    aux->next = temp;

    //printf("PROBANDO%li", temp->value);
    //free(*stack);
    //ESTAMOS EN ELLO.....LEAKS AKI.
    
    
}