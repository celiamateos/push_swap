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

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	int		i;

	if (argc < 2)
		return (1);
	i = 1;
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	*stack_a = NULL;
	while (i != argc)
	{
		ft_fill_stack(argv[i], stack_a);
		i++;
	}
	if (ft_stacksize(*stack_a) < 2)
		ft_error1(stack_a, 0);
	ft_start(stack_a);
	ft_stackclear(stack_a);
	exit (0);
	return (0);
}

void	ft_start(t_stack **stack_a)
{
	int		stack_size;
	t_stack	**stack_b;

	stack_size = ft_stacksize(*stack_a);
	if (stack_size < 2)
		ft_error1(stack_a, 0);
	ft_check_arg(stack_a);
	ft_index(stack_a, stack_size);
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_b)
		ft_error1(stack_a, 0);
	*stack_b = NULL;
	if (ft_stacksize(*stack_b) == 0)
		push_swap(stack_a, stack_b);
	free (stack_b);
}

void	ft_print_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL)
		ft_printf("\n\nStack_a is null");
	if (stack_b == NULL)
		ft_printf("\n\nStack_b is null");
	while (stack_a)
	{
		ft_printf("\nSTACK_A VALUE:%d", stack_a->value);
		ft_printf("\nSTACK_A      index:%d", stack_a->index);
		stack_a = stack_a->next;
	}
	ft_printf("\n\n\n");
	while (stack_b)
	{
		ft_printf("\n\nSTACK_B:%d", stack_b->value);
		stack_b = stack_b->next;
	}
}
