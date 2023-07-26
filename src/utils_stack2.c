/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:38:52 by cmateos           #+#    #+#             */
/*   Updated: 2023/07/20 16:38:54 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
//Se supone que esta funcion libera el contenido del nodo y el nodo
//pero no hace nada.
void	ft_stackdelone(t_stack *stack)
{
	if (stack)
		{
			free (stack);
			//free (&stack->value);
			//free (&stack->index);
		}
	//free (stack);

}
// Se supone que esta funcion itera la lista y elimina cada nodo
//aplicando la funcion anterior y SI FUNCIONA. jaja es de coña.
void	ft_stackclear(t_stack **stack)
{
	t_stack  *temp;

	temp = *stack;
	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
