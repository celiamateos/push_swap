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

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (ft_stacksize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else if (ft_stacksize(*stack_a) == 4)
		ft_sort_four(stack_a, stack_b);
	else if (ft_stacksize(*stack_a) == 5)
		ft_sort_five(stack_a, stack_b);
	else if (ft_stacksize(*stack_a) > 5)
		ft_radix_sort(stack_a, stack_b);
}

int	ft_is_sort(t_stack **stack)
{
	t_stack	*temp;

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

void	ft_radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		i;
	int		j;
	int		len_stack;
	int		max_bits;

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

int	ft_max_bits(t_stack **a)
{
	t_stack	*temp;
	int		index_max;
	int		max_bits;

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
