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
		ft_putstr_fd("\x1b[1;31mError\n\x1b[0m", 2);
	if (n == 2)
		ft_putstr_fd("\x1b[1;31mError\n\x1b[0m", 2);
	if (n == 3)
		ft_putstr_fd("\x1b[1;31mError\n\x1b[0m", 2);
	if (n == 4)
		ft_putstr_fd("\x1b[1;31mError\n\x1b[0m", 2);
	if (stack_a)
	{
		ft_stackclear(stack_a);
		stack_a = NULL;
	}
	exit (1);
}
