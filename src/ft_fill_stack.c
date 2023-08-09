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

void	ft_fill_stack(char *arg, t_stack **stack_a)
{
	int	i;
	int	is_str;

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

void	ft_is_str(char *str, t_stack **stack_a)
{
	char	**array;
	int		i;

	i = 0;
	array = ft_split(str, ' ');
	if (array == NULL)
		ft_error1(stack_a, 0);
	while (array[i])
	{
		ft_is_num(array[i], stack_a);
		if (array[i] != NULL)
			free (array[i]);
		i++;
	}
	free (array);
}

void	ft_is_num(char *str, t_stack **stack_a)
{
	t_stack	*node;
	int		nb;

	nb = 0;
	nb = ft_atoi_pushswap(str, stack_a);
	node = ft_newnode(nb);
	if (node == NULL)
		ft_error1(stack_a, 0);
	ft_stackadd_back(stack_a, node);
}
