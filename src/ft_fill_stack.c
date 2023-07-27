/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:49:26 by cmateos           #+#    #+#             */
/*   Updated: 2023/07/20 16:49:37 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
/* Esta función toma cada argumento pasado como parametro y verifica que los
caracteres estén entre 0 y 9 y añade cada número a cada uno de los nodos que
conformaran el stack_a. 
En caso de que haya varios números entre comillas  (is_str, entonces hace un split y atoi.)*/
void    ft_fill_stack(char *arg, t_stack **stack_a)
{
    int i;
    int is_str;

    i = 0;
    is_str = 0;
    while (arg[i])
    {
        if ((arg[i] > '9' && arg[i] != ' ' && arg[i] != '-')
            || (arg[i] < '0' && arg[i] != ' ' && arg[i] != '-')
            || (arg[i] == '-' && arg[i + 1] == ' ')
            || (arg[i] == '-' && arg[i + 1] == '\0')
            || (arg[i] != ' ' && arg[i + 1] == '-'))
            ft_error1(stack_a, 1);
        if (arg[i] == ' ')
            is_str = 1;
        i++;
    }
    if (is_str == 1)
        ft_is_str(arg, stack_a);
    else
        ft_is_num(arg, stack_a);
}

void ft_is_str(char *str, t_stack **stack_a)
{
    char **array;
    t_stack *node;
    int     i;
    long int     nb;

    nb = 0;
    i = 0;
    array = ft_split(str, ' ');
    while (array[i])
    {
        nb = ft_atoi_pushswap(array[i], stack_a);
        if (nb > INT_MAX || nb < INT_MIN)
            ft_error1(stack_a, 2);
        node = ft_newnode(nb);
        ft_stackadd_back(stack_a, node);
        if (array[i] != NULL)
            free (array[i]);
        i++;
    }
    free (array);
}

void ft_is_num(char *str, t_stack **stack_a)
{
    t_stack *node;
    long int    nb;

    nb = 0;
    nb = ft_atoi(str);
    if (nb > INT_MAX || nb < INT_MIN)
        ft_error1(stack_a, 2);
    node = ft_newnode(nb);
    ft_stackadd_back(stack_a, node);
}