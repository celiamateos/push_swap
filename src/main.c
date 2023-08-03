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

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	//atexit(ft_leaks);
	t_stack	**stack_a;
	int		i;

	i = 1;
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a || argc < 2)
		return (0);
	*stack_a = NULL;
	while (i != argc)
	{
		ft_fill_stack(argv[i], stack_a);
		i++;
	}
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
	ft_stackclear(stack_b);
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
