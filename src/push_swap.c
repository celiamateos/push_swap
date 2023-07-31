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
    if (ft_stacksize(*stack_a) == 4)
      ft_sort_four(stack_a, stack_b);
    if (ft_stacksize(*stack_a) == 5)
      ft_sort_five(stack_a, stack_b);
    else
        ft_radix_sort(stack_a, stack_b);
}

void    ft_sort_five(t_stack **a, t_stack **b)
{
    int min;
    min = ft_min_index(*a);
    //printf("\nMIN_INDEX:%d", min);
    if ((*a)->next->index == min)
        ft_do_sa(a);
    else if ((*a)->next->next->index == min)
    {
        ft_do_ra(a);
        ft_do_ra(a);
    }
    else if ((*a)->next->next->next->index == min)

    {
        ft_do_rra(a);
        ft_do_rra(a);
    }
    else if ((*a)->next->next->next->next->index == min)
        ft_do_rra(a);
    ft_do_pb(a, b);
    ft_sort_four(a, b);
    ft_do_pa(b, a);
}
void    ft_sort_three(t_stack **stack)
{
    int     second;
    int     first;
    int     third;

    first = (*stack)->index;
    second = (*stack)->next->index;
    third = (*stack)->next->next->index;
    if (first + 1 == second && second + 1 == third)
        return ;
    if (first > second && first < third)
        ft_do_sa(stack);
    else if (first < second && first > third)
        ft_do_rra(stack);
    else if (first > second && second < third)
        ft_do_ra(stack);
    else if (first < second && second > third)
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

void    ft_sort_four(t_stack **a, t_stack **b)
{
    int min;
    min = ft_min_index(*a);
    //printf("\nMIN_INDEX:%d", min);
    if ((*a)->index + 1 == (*a)->next->index &&
        (*a)->next->index + 1 == (*a)->next->next->index &&
        (*a)->next->next->index + 1 == (*a)->next->next->next->index)
        return ;
    if ((*a)->next->index == min)
        ft_do_sa(a);
    else if ((*a)->next->next->index == min)
    {
        ft_do_rra(a);
        ft_do_rra(a);
    }
    else if ((*a)->next->next->next->index == min)
        ft_do_rra(a);
    ft_do_pb(a, b);
    ft_sort_three(a);
    ft_do_pa(b, a);
}

int ft_min_index(t_stack *min)
{
    t_stack *temp;
    temp = min->next;
    //int     min_index;

    while (temp != NULL)
    {
        if (min->index > temp->index)
            {
                min = temp;
                if (temp->next == NULL)
                    break ; 
                else
                    temp = temp->next;
            }
        else if (min->index < temp->index)
            {
                if (temp->next != NULL)
                    temp = temp->next;
                else
                    break ;
            }
    }
    //min_index = min->index;
    return (min->index);
}
int   ft_is_sort(t_stack **stack)
{
    t_stack *temp;

    temp = (*stack)->next;
    if (ft_stacksize(*stack) < 2)
        return (1);
    while (temp != NULL)
    {
        if ((*stack)->index + 1 != temp->index)
            break ;
        else if (temp->next == NULL)
            return (1);
        *stack = (*stack)->next;
        temp = temp->next;
    }
    return (0);
}

void    ft_radix_sort(t_stack **a, t_stack **b)
{
    t_stack *temp;
    int i;
    int j;
    int len_stack;
    int max_bits;

    i = 0;
    temp = *a;
    max_bits = ft_max_bits(a);
    len_stack = ft_stacksize(*a);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < len_stack)
        {
            temp = *a;
            if (((temp->index >> i) & 1) == 1)
                ft_do_ra(a);
            else
                ft_do_pb(a, b);
        }
        while (ft_stacksize(*b) != 0)
            ft_do_pa(b, a);
        i++;
    }

}

int   ft_max_bits(t_stack **a)
{
    t_stack *temp;
    int     index_max;
    int     max_bits;

    temp = *a;
    index_max = temp->index;
    max_bits = 0;
    while (temp)
    {
        if (temp->index > index_max)
            index_max = temp->index;
        temp = temp->next;
    }
    while ((index_max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

