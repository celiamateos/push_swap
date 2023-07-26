/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:18:36 by cmateos           #+#    #+#             */
/*   Updated: 2023/07/19 14:18:37 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
/*@brief ALOCA MEMORIA*/
//Crea un nodo y lo retorna, el parametro es el contenido con el que crear el nodo.
t_stack *ft_newnode(long int nb)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = nb;
	node->index = -1;
    node->next = NULL;
    return (node);
}
//Añade el nodo al final del stack (abajo)
void ft_stackadd_back(t_stack **stack, t_stack *node)
{
    t_stack *temp;

    if (!node)
        return ;
    if (!*stack)
        *stack = node;
    temp = ft_stacklast(*stack);
    temp->next = node;
    node->next = NULL;
}
//Añade el nodo al principio del stack (arriba)
void	ft_stackadd_front(t_stack **stack, t_stack *node)
{
	if (stack)
	{
		if (*stack)
			node->next = *stack;
		*stack = node;
	}
}

//Devuelve el último nodo del stack, el de abajo del todo.
t_stack	*ft_stacklast(t_stack *node)
{
	t_stack	*lastnode;

	lastnode = node;
	if (lastnode)
	{
		while (lastnode->next != NULL)
			lastnode = lastnode->next;
	}
	return (lastnode);
}

//Devuelve la cantidad de nodos que tiene el stack.
int	ft_stacksize(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	temp = lst;
	i = 0;
	if (temp)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			i++;
		}
		if (temp->next == NULL)
			i++;
	}
	return (i);
}
