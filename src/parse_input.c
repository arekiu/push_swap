/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:59:09 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/19 13:39:20 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_str2(char *str_arr[], int len)
{
	int				*num_arr;
	int				i;
	long long		num;

	i = 0;
	num_arr = malloc(sizeof(int) * len);
	if (!num_arr)
		return (free_str_arr(str_arr));
	while (i < len)
	{
		num = ft_atoll(str_arr[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_invalid(num_arr);
			return (NULL);
		}
		num_arr[i] = (int)num;
		i++;
	}
	return (num_arr);
}

int	*parse_str(char *str)
{
	int		*num_arr;
	int		i;
	char	**str_arr;

	i = 0;
	str_arr = ft_split(str, ' ');
	if (has_duplicates(str_arr))
		return (free_str_arr(str_arr));
	while (str_arr[i] != NULL)
	{
		if (!is_int(str_arr[i]))
			return (free_str_arr(str_arr));
		i++;
	}
	num_arr = parse_str2(str_arr, i);
	if (!num_arr)
		return (free_str_arr(str_arr));
	free_str_arr(str_arr);
	return (num_arr);
}

int	*parse_multi(int argc, char *argv[])
{
	int				i;
	int				*num_arr;
	long long		num;

	i = 0;
	if (has_duplicates(argv))
		return (0);
	num_arr = malloc(sizeof(int) * (argc - 1));
	if (!num_arr)
		return (NULL);
	while (i < argc - 1)
	{
		if (!is_int(argv[i + 1]))
			return (free_invalid(num_arr));
		num = ft_atoll(argv[i + 1]);
		if (num > INT_MAX || num < INT_MIN)
			return (free_invalid(num_arr));
		num_arr[i] = (int)num;
		i++;
	}
	return (num_arr);
}

int	*parse_input(int argc, char *argv[])
{
	int	*int_arr;

	if (argc == 2)
		int_arr = parse_str(argv[1]);
	else
		int_arr = parse_multi(argc, argv);
	if (!int_arr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (int_arr);
}
