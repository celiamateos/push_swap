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

void    ft_index(t_stack **a, int stack_size)
{
    t_stack *temp;
    long int     value;
 
    temp = *a;
    value = 0;
    while (stack_size > 0)
    {
        temp = *a;
        while (temp != NULL)
        {
            if (temp->value > value && temp->index == -1)
                value = temp->value;
            temp = temp->next;
        }
        printf("\nBIGNUM:%li", value);
        temp = *a;
        while (temp != NULL)
        {
            if (temp->value == value)
                temp->index = stack_size;
            temp = temp->next;
        }
        value = 0;
        stack_size--;
        //printf("\n         index =%i", temp->index);
    }
    /*while (stack_size > 0)
    {
        ft_bignum(stack_a, temp, stack_size);
        stack_size--;
    }*/
}


/*void    ft_bignum(t_stack *stack_a, t_stack *temp, int stack_size)
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
                stack_a = ft_stacklast(stack_a);
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
        else
            stack_a = stack_a->next;
    }
    stack_a->index = stack_size;
 //   printf("\nBIGNUM:%li", stack_a->value);
 //   printf("\n         index =%i", stack_a->index);
}*/