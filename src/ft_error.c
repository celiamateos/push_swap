/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:55:25 by cmateos           #+#    #+#             */
/*   Updated: 2023/07/20 19:55:35 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ft_error1(t_stack **stack_a, int n)
{
	if (n == 1)
		printf("\x1b[1;31m\nError, invalid character\x1b[0m");
	if (n == 2)
		printf("\x1b[1;31m\nNumber can´t should be INT_MAX or INT_MIN\x1b[0m");
	if (n == 3)
		printf("\x1b[1;31m\nError, repeated numbers\x1b[0m");
	if (n == 4)
		printf("\x1b[1;31m\nError, Number is > INT_MAX or < INT_MIN \x1b[0m");
	if (stack_a)
	{
		ft_stackclear(stack_a);
		stack_a = NULL;
	}
	exit (1);
}
