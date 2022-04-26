/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:44:33 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/08/05 16:27:42 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	int		counter;

	sign = 1;
	result = 0;
	counter = 0;
	while (ft_isspace (str[counter]))
		counter ++;
	if (str[counter] == '+')
		counter++;
	else if (str[counter] == '-')
	{
		sign = -1;
		counter++;
	}
	while (ft_isdigit(str[counter]))
	{
		result = result * 10 + (str[counter] - '0');
		counter++;
	}
	return (result * sign);
}
