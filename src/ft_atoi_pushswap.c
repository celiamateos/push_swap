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

long int	ft_atoi_pushswap(const char *str, t_stack **stack_a)
{
	unsigned int	i;
	unsigned long int	result;
	unsigned int	sign;
	long long	check;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
			i++;
	ft_check_char(str[i], stack_a);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	check = result;
	if (check > INT_MAX || check < INT_MIN)
		ft_error1(stack_a, 5);
	return (sign * result);
}

void	ft_check_char(char c, t_stack **stack_a)
{
	if ((c > '9' && c != ' ' && c != '-')
        || (c < '0' && c != ' ' && c != '-')
        || (c == '-' && c + 1 == ' ')
        || (c <= '9' && c + 1== '-')
        || (c >= '0' && c + 1 == '-' ))
            ft_error1(stack_a, 1);
}