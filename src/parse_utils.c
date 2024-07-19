/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:03:55 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/19 12:42:06 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nums(char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (counter);
		counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

int	has_duplicates(char *arr[])
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (arr[i] != NULL)
	{
		str = arr[i];
		j = i + 1;
		while (arr[j] != NULL)
		{
			if (ft_strcmp(str, arr[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || ((str[0] == '-' || str[0] == '+') && str[1] == '\0'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
