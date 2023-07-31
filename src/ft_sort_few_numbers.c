/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_few_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:47:45 by cmateos           #+#    #+#             */
/*   Updated: 2023/07/31 19:47:46 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	min;

	min = ft_min_index(*a);
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

void	ft_sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = ft_min_index(*a);
	if ((*a)->index + 1 == (*a)->next->index
		&& (*a)->next->index + 1 == (*a)->next->next->index
		&& (*a)->next->next->index + 1 == (*a)->next->next->next->index)
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

void	ft_sort_three(t_stack **stack)
{
	int	second;
	int	first;
	int	third;

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

int	ft_min_index(t_stack *min)
{
	t_stack	*temp;

	temp = min->next;
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
	return (min->index);
}
