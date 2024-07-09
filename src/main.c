/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:34:51 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/09 16:59:07 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_str(char *str)
{
	int		*num_arr;
	int		i;
	int		len;
	char	**str_arr;

	i = 0;
	len = 0;
	str_arr = ft_split(str, ' ');
	while(str_arr[len] != NULL)
		len++;
	num_arr = malloc(sizeof(int) * len);
	if (!num_arr)
	{
		free (str_arr);
		return (0);
	}
	while (i < len)
	{
		num_arr[i] = ft_atoi(str_arr[i]);
		i++;
	}
	free (str_arr);
	return (num_arr);
}

int	main(int argc, char *argv[])
{
	int		i;
	//t_list	num_list;
	int	*num_arr;

	if (argc == 1)
	{
		ft_printf("You must provide a list of numbers");
		return (0);
	}
	else if(argc == 2)
	{
		num_arr = parse_str(argv[1]);

	}
	i = 0;
	while (i < 4)
	{
		ft_printf("El num %d\n", num_arr[i]);
		i++;
	}
	free (num_arr);
	return (0);
}
