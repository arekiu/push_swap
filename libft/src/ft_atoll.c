/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:05:31 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/15 13:38:23 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	convert_to_ll(const char *str, int negative)
{
	int			i;
	long long	new_num;

	i = 0;
	new_num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (new_num > (LLONG_MAX - (str[i] - '0')) / 10)
		{
			if (negative == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		new_num = (new_num * 10) + (str[i] - '0');
		i++;
	}
	return (new_num * negative);
}

long long	ft_atoll(const char *str)
{
	int			i;
	int			negative;

	i = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = -1;
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	return (ft_convert_to_ll(&str[i], negative));
}
