/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:26:39 by cmateos           #+#    #+#             */
/*   Updated: 2023/07/20 17:26:41 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ft_check_arg(t_stack **stack_a)
{
	if (ft_repeated_number(*stack_a) == 1)
		ft_error1(stack_a, 3);
	if (ft_numbers_is_sorted(*stack_a) == 1)
		ft_error1(stack_a, 4);
}

int	ft_repeated_number(t_stack *stack_a)
{
	t_stack	*temp;
	int		repeated;

	repeated = 0;
	while (stack_a->next != NULL)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (temp->value == stack_a->value)
			{
				repeated = 1;
				break ;
			}
			temp = temp->next;
		}
		if (repeated == 1)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_numbers_is_sorted(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	temp = temp->next;
	while (temp->next != NULL)
	{
		if (!(stack_a->value < temp->value))
			break ;
		stack_a = stack_a->next;
		temp = temp->next;
	}
	if (temp->next == NULL && stack_a->value < temp->value)
		return (1);
	return (0);
}
