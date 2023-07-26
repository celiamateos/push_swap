/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:25:31 by cmateos           #+#    #+#             */
/*   Updated: 2023/07/24 13:25:43 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_index(t_stack **stack_a, int stack_size)
{
    t_stack **temp;

    temp = (t_stack **)malloc(sizeof(t_stack));
    temp = stack_a;
    printf("\nStack_size%i\n\n", stack_size);
    while (stack_size > 0)
    {
        ft_bignum(*stack_a, *temp, stack_size);
        stack_size--;
    }
    //ft_stackclear(temp);
    //printf("\ndic mem temp%p", temp);
    //temp = NULL;
    //free (temp);
   //1 LEAKS DE MEMORIA POR TEMP; pero si lo libero aqui, borro tn stack_A T.T
}

void    ft_bignum(t_stack *stack_a, t_stack *temp, int stack_size)
{
    temp = stack_a->next;
    while (stack_a)
    {
        if (stack_a->index == -1)
        {
            if ((stack_a->value > temp->value
                || temp->index != -1) && (temp->next != NULL))
                    temp = temp->next;
            else if ((stack_a->value < temp->value && temp->index == -1)
                && (temp->next != NULL))
            {
                stack_a = temp;
                temp = temp->next;
            }
            else if ((stack_a->value < temp->value && temp->index == -1)
                && (temp->next == NULL))
            {
                while (stack_a->next != NULL)
                    stack_a = stack_a->next;
                break ;
            }
            else
                break ;
        }
        else if (stack_a->index != -1 && temp->next != NULL)
        {
            stack_a = stack_a->next;
            temp = temp->next;
        }
    }
    stack_a->index = stack_size;
    //printf("\nBIGNUM:%li", stack_a->value);
    //printf("\n         index =%i", stack_a->index);
}