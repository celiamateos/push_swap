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
/*@brief ALOCA MEMORIA, exit si falla la reserva de memoria*/
t_stack	*ft_newnode(int nb)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		exit (1);
	node->value = nb;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	ft_stackadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*temp;

	if (!node)
		return ;
	if (!*stack)
		*stack = node;
	temp = ft_stacklast(*stack);
	temp->next = node;
	node->next = NULL;
}

void	ft_stackadd_front(t_stack **stack, t_stack *node)
{
	if (stack)
	{
		if (*stack)
			node->next = *stack;
		*stack = node;
	}
}

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
