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

void	ft_index(t_stack **a, int stack_size)
{
	t_stack	*temp;
	int		value;

	temp = *a;
	value = INT_MIN;
	while (stack_size > 0)
	{
		temp = *a;
		while (temp != NULL)
		{
			if (temp->value > value && temp->index == -1)
				value = temp->value;
			temp = temp->next;
		}
		temp = *a;
		while (temp != NULL)
		{
			if (temp->value == value)
				temp->index = stack_size;
			temp = temp->next;
		}
		value = INT_MIN;
		stack_size--;
	}
}
