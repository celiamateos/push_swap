/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:18:54 by cmateos           #+#    #+#             */
/*   Updated: 2023/07/26 16:19:09 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_pushswap(const char *str, t_stack **stack_a)
{
	unsigned int	i;
	unsigned int	result;
	unsigned int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
			i++;
    if ((str[i] > '9' && str[i] != ' ' && str[i] != '-')
        || (str[i] < '0' && str[i] != ' ' && str[i] != '-')
        || (str[i] == '-' && str[i + 1] == ' ')
        || (str[i] <= '9' && str[i + 1] == '-')
        || (str[i] >= '0' && str[i + 1] == '-' ))
            ft_error1(stack_a, 1);
	if (str[i] == '-')
		sign = sign * (-1);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (sign * result);
}