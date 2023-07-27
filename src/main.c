/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:36:10 by cmateos-          #+#    #+#             */
/*   Updated: 2023/07/17 19:19:46 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
void    ft_leaks(void)
{
    system("leaks -q push_swap2");
}

int main(int argc, char **argv)
{
    //atexit(ft_leaks);
    t_stack     **stack_a;
    t_stack     **stack_b;
    int         stack_size;
    int i;

    i = 1;
    //printf("\nARGC:%i", argc);
    if (argc < 3)
    {
        printf("\nError, min 3 argc");
        exit (1);
    }
    stack_a = (t_stack **)malloc(sizeof(t_stack));
    if (!stack_a)
        return (0);
    *stack_a = NULL;
    while (i != argc)
    {
        ft_fill_stack(argv[i], stack_a);
        i++;
    }

    stack_size = ft_stacksize(*stack_a);
    if (!stack_size)
        return (0);
    //printf("\nStack_a tiene %i nodos", stack_size);
    ft_check_arg(stack_a);
    stack_b = (t_stack **)malloc(sizeof(t_stack));
    if (!stack_b)
        ft_error1(stack_a, 0);
    *stack_b = NULL;
    ft_index(stack_a, stack_size);

    ft_print_stack(*stack_a, *stack_b);
    //ft_swap_ab(*stack_a);
    //ft_push_ab(stack_a, stack_b);
    ft_reverse_rotate(*stack_a);
    printf("\n\n\n\n DESPUÉS DE ROTATE:");
    ft_print_stack(*stack_a, *stack_b);
    exit (1);
    return (0);
}





void    ft_print_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a == NULL)
        printf("\n\nStack_a is null");
    if (stack_b == NULL)
        printf("\n\nStack_b is null");
    while (stack_a)
    {
       printf("\nSTACK_A VALUE:%ld", stack_a->value);
       printf("\nSTACK_A      index:%d", stack_a->index);
       stack_a = stack_a->next;
    }
    printf("\n\n\n");
    while (stack_b)
    {
       printf("\n\nSTACK_B:%ld", stack_b->value);
       stack_b = stack_b->next;
    }
}
/*int main (void)
{
    t_list  *stack_a;
    t_list  *stack_b;
    t_list *nodo1;
    t_list *nodo2;

    stack_a = NULL;
    stack_b = NULL;

    nodo1 = ft_lstnew("nodo1");
    nodo2 = ft_lstnew("nodo2");
    ft_lstadd_back( &stack_a, nodo1);
    ft_lstadd_back( &stack_a, nodo2);

    while (stack_a)
    {
       printf("\nstack_a:%s", stack_a->content);
       stack_a = stack_a->next;
    }

    //push_b(&stack_a, &stack_b, nodo1);

    stack_b = ft_lstnew(nodo1);
    ft_lstadd_front(&stack_b, nodo1);
    //ft_lstdelone(nodo1, free);

    while (stack_b)
    {
       printf("\nstack_b:%s", stack_b->content);
       stack_b = stack_b->next;
    }

    while (stack_a)
    {
       printf("\nstack_a:%s", stack_a->content);
       stack_a = stack_a->next;
    }

    return (0);
}*/
